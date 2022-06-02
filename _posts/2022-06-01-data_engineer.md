---
layout: post
title:  "Data Engineering Interview Preparation"
date:   2022-06-01 21:00:00 -0700
categories: data engineer sql python sqlite interview
---

This Spring marks the completion of my post-graduate Masters degree in Computer Science. What comes next? Well, LinkedIn bombards my email with 30+ jobs every day for remote work as a ''data engineer''. Looking at the job description reveals similar keywords. One job asking for someone with, ``experience migrating and deploying cloud-based solutions'' has the following keywords:

- SQL (data transformations, statistical analysis)
- Programming (Python, Java, Scala)
- Visualization (Tableau, Power BI)
- Cloud platforms (AWS, GCP, Azure, Snowflake, troubleshooting between systems)
- Extract-transform-load (ETL, Databricks)
- Deploying software (CI/CD pipeline)
- Microsoft Office
- Certification as an active Data Engineer and/or Architect from major cloud platforms.
- ``Deliver quality results in a cross-functional work environment.''

Microsoft Office, ditto. Let's research the first qualifications: SQL and programming.

## SQL

SQL (pronounced ''see-quell'', or ''S-Q-L'') is how to politely ask a computer for data records. A record is a single row vector with enforced typing. Many records are stored together in Tables. Working with these Tables is what SQL does. A simple example would be a table of house sales with features: price, house size, and location. Creating a table can be done with several lines of SQL (if you have an Ubuntu environment available, type `$ sqlite3` in the command line and the prompt will execute any SQL commands in a temporary database.)

{% highlight SQL %}
CREATE TABLE home_sales (
    price INTEGER,
    sqft_living INTEGER,
    bedrooms INTEGER,
    floors REAL, 
    zipcode INTEGER
);
{% endhighlight %}

To delete this table, type `DROP Table home_sales;`. Now let's add some data.

<table>
  {% for row in site.data.house_sales %}
    {% if forloop.first %}
    <tr>
      {% for pair in row %}
        <th>{{ pair[0] }}</th>
      {% endfor %}
    </tr>
    {% endif %}
    
    {% if forloop.index0 < 6 %}
        {% tablerow pair in row %}
        {{ pair[1] }}
        {% endtablerow %}
    {% endif %}
  {% endfor %}
</table>

We'll show two ways to load data. First the manual way.

{% highlight SQL %}
INSERT INTO home_sales (price, sqft_living, bedrooms, floors, zipcode)
VALUES
    (313000, 1340,3, 1.5, 98133),
    (435000, 1840,5, 1, 98133),
    (2384000, 3650,5, 2, 98119),
    (740000, 2010,4, 1.5, 98119),
    (342000, 1930,3, 1, 98042),
    (490000, 880, 2 ,1, 9811);
{% endhighlight %}

Verify the transaction by selecting all of the data `SELECT * FROM home_sales;`.

An interesting statistic is how much the price increases by the size of the house. Viewing price in order helps draw the eye to patterns. Small numbers also facilitate working with multiples, but the integer cannot cast the result to a `REAL`.

{% highlight SQL %}
SELECT price, sqft_living 
FROM home_sales
ORDER BY price;
{% endhighlight %}

price|sqft_living
-----|-----------
313000|1340
342000|1930
435000|1840
490000|880
740000|2010
2384000|3650

Houses generally get bigger with prices. SQL really excels at understanding logic. For example, given `home_sales` what is the second most expensive home in each zipcode? The following script answers this query.

{% highlight SQL %}
SELECT zipcode, price as SecondHighestPrice
FROM (
    SELECT RANK() OVER (
        PARTITION BY zipcode
        ORDER BY price DESC
    ) row_num,
    price,
    zipcode
    FROM home_sales) as sales
WHERE row_num = 2; 
{% endhighlight %}

Complex queries should be read from inside out. First selction adds a ranking variable grouped by zipcode, and ordered from most expensive to least expensive. The result is passed to another selection with the alias `sales`. The outer table selection picks the two columns of interest, and filters out rows that are not the second highest price.

Another interesting question is how many zipcodes have sold houses worth at least $400k?

{% highlight SQL %}
WITH counts AS(
    SELECT COUNT(*) as cnt
    FROM home_sales
    WHERE price >= 400000
    GROUP BY zipcode
) 
SELECT COUNT(cnt)
FROM counts;
{% endhighlight %}

This query uses a Common Table Expression (CTE). First, filter where homes are less than $400k, then select the count of each zipcode group. Then just count the number of rows returned from the CTE. 

Questions I have seen on interviews and training websites use nested queries like shown above. Typically they provide a schema and data, then ask a question in English which must be answered from the schema. One type of feature I see missing in these toy interview questions are lack of `JOINS`. In a commerical data warehouse environment, dozens of tables are loosely linked to each other by `PRIMARY` and `FOREIGN` `KEYS`. Tables have only one `PRIMARY KEY` column, typically a form of *id*, and is a unique. Other tables can reference columns within the `PRIMARY KEY` table just like any other column. This type of architecture is called *relational*. For example, comparing the number of houses sold per population in each zipcode requires a population per zipcode table. The primary key is zipcode, and the value is population. 

{% highlight SQL %}
CREATE TABLE zippop(
    zipcode INTEGER PRIMARY KEY,
    pop INTEGER
);
INSERT INTO zippop(zipcode, pop)
VALUES
    (98133, 49476),
    (98119, 26898),
    (98042, 49118),
    (98115, 55519);
{% endhighlight %}

Since each value in zipcode is unique, it can be joined to the `home_sales`.

{% highlight SQL %}
WITH counts AS(
    SELECT 
        zipcode,
        COUNT(*) as cnt
    FROM home_sales
    GROUP BY zipcode
) SELECT 
    counts.zipcode,
    cnt, 
    pop
FROM counts
INNER JOIN zippop
    ON counts.zipcode = zippop.zipcode;    
{% endhighlight %}

zipcode|cnt|pop
-------|---|---
98042|1|49118
98119|2|26898
98133|2|49476

These queries demonstrate proficiency with basics, and are probably sufficient for screening job applicants to reasonable numbers. LinkedIn reports some remote job opportunities have over 100+ applicants. If a recruiter can schedule ten 30-minutes interviews a day, or 50 per week, then getting below the 50% quartile with a resume lookover is a big step. 

## Programming

Programming requires manipulating arrays, objects, or other Abstract Data Types efficiently and precisely. Computer Science degrees stress how long it takes to iterate through a list with `n` elements, and then how long it takes to sort that list `O(n^2)`, or `O(log(n)*n)`. The difference is staggering for large `n`, which is typical. Apparently this skill is hard to grasp, which is why coding interviews stress this concept. Although in practice I find myself using library provided iterators which optimally perform their tasks.

Programming languages flourish these days, and that's both a good and a bad thing. Bad because multiple languages create learning-curve barriers to development. Good because languages can specialize without an overbearing committee or corporation controlling the codebase. A popular open source language is Python. It has freely available libraries for generic programming, scientific computing, and web development.

A simple Python program could perform the following: given a list and two indices reverse the elements between the indices. Some constraints apply to the input: the list must have at least 1 element and less than 500, the left and right indicies must be in order, and all elements should be in the range -500 to 500.

{% highlight Python %}
def reverse_list(head, left, right):
    # Precondition check
    N = len(head)
    if N < 1 or N > 500:
        return head
    if right < left or left < 1 or right > N:
        return head
    bounds = [x for x in head if x < -500 or x > 500]
    if len(bounds) > 0:
        return head

    cpy = head.copy()  # Deep copy reference
    aux = cpy[left-1:right]  # Copy a slice
    cpy[left-1:right] = aux[:: -1]  # Set range to be reversed elements
    return cpy
{% endhighlight %}

After testing the inputs, the problem is addressed in three lines of code. Python passes list functional arguments as shallow copies, meaning the function scope is the same data that exists within the global scope. Changing an element in the function affects the list in the caller. This is good for storage reasons to prevent copying redundant data. But in this case a new list is required for the return value. The first line makes a deep copy of the list input. Then a slice is taken. Python is index-by-0, so accessing the second element is index `[1]`. The slice selects all elements up to that index, *e.g.*, `[1:4]` returns 3 elements between the second and fourth indices. The third line of code replaces the range with its elements reversed. A *Pythonic* slice notation `[::-1]` selects all elements in reverse order.

Another type of problem how to computer the `n`th element in a sequence of positive integers divisible by `a`, `b`, or `c`.

{% highlight Python %}
def ugly_number(n, a, b, c):
    # Precondition
    if n < 1 or a < 1 or b < 1 or c < 1:
        return 0
    if n > 10E9 or a > 10E9 or b > 10E9 or c > 10E9:
        return 0
    prod = a * b * c
    if prod < 1 or prod > 10E18:
        return 0

    # Initialize
    count = 0
    num = 2
    while True:
        # Check condition
        if num % a == 0 or num % b == 0 or num % c == 0:
            count += 1
            if count == n:
                return num
        num += 1  # iterate
{% endhighlight %}

Once again preconditions on the input apply. This problem is readily solved with iteration. Each increment of a counter checks if it's divisible by `a`, `b`, or `c`. The iteration is guaranteed to terminate because `n` was checked to be within range. The runtime analysis is `min([a, b, c]) * n` or `O(n)` in big-oh notation.

Complexity plays a big role in computer science, and no other subject is more studied than sorting. A sort requires knowing how one element compares to every other element. For example, bubble sort compares every element with every other element with complexity `O(n^2)` . In contrast mergesort uses a divide and conquer approach. At each iteration, divide the problem in two, then recursively process the halves. Surprisingly, this yields a smaller complexity `O(log(n)*n)`. Sort algorithms are the bedrock of a computer science education, and there is no practical application for them. And you can copy-paste the code from Stack Overflow whenever the source is required.

## Future Work and Conclusion

For my coding interview I trained on [Codility](https://app.codility.com/programmers/). The site has some programming and SQL problems and provides automated test feedback to improve skills. Spending an afternoon on the site improved my confidence a lot and it paid off during the skill test.   

Unfortunately no amount of studying will suffice for real world experience. Practicing with toy datasets and contrived problems will develop basic skills but not the intuition and inspiration to dive into large datasets without getting overwhelmed. Unfortunately I do not know where else to find this experience. If I find a way I will post.

So far I've discussed the first two items (SQL, Programming) in the job description from the introduction. Next post I will write about what I know of something else on the list.