---
layout: post
title:  "Thanksgiving and Graduate School"
date:   2022-11-24 08:08:16 -0700
categories: update school
---



After two years after detouring back into university life, in August I graduated with a Masters in Computer Science & Engineering! Graduate school is not like undergrad. No one cares about GPA, or how smart you are. Instead the goal is to produce original research in the form of an 8 page, double column, conference paper. The research can be about anything: computer graphics, pattern recognition, or human-robot interaction. Good papers address a specific problem: how to generate a robot inspection path through a building, how to classify faces from images, or why do people overtrust robots? Starting with a good problem yields an interesting research project.

## Research and Problem Formulation

My [thesis]({{ site.url }}/img/ICHMS_2022_Submission.pdf) started with reading a [conference paper](https://ieeexplore-ieee-org.unr.idm.oclc.org/abstract/document/8520654) assigned in my Human-Robot Interaction class. Apparently there's an entire group of people dedicated to understanding how people react to robots in the real world environments. For example, would you pour orange juice on a plant if a robot asked you to? The experimental results showed most people would comply with this unusual request. This question baffled me and my group. We set out to brainstorm ideas of how to create a more realistic experiment and show people are not so trusting. But as academic projects usually go, this one almost failed from the outset. One of our members became ill for most of the semester, our robot stopped working, and I was getting worn out from balancing my own research, teaching duties, and coursework. At the end of the semester we had nothing to show for our work, the robot refused to operate, and both my teammates moved on from UNR. Thus I was left alone to complete the project within the following semester.

Forced to complete this task, I resolved to turn this idea into a substantial thesis. Researching over winter break, I found related works involving overtrust in an emergency evacuation and letting an unknown robot into a secure dormitory. A general idea emerged that it is hard to get people in experiments to disobey requests from a robot. The reason for this is because people agreed to be in the experiment in the first place, and they would strongly prefer to comply with additional requests because they're in the experiment. This "foot-in-the-door" effect is not new knowledge, but the question emerged of how much information do people need to comply with a strange request from a robot? 

## Engineering and Experiment Design

With a question in hand, I just needed a working robot to run an experiment with, however that took months of headbanging frustration to overcome. After two months failing to troubleshoot one system, I switched to a different robot that I pulled out of my advisor's closet. Then spent another month installing the operating system, ROS, and troubleshooting the electronics and wifi signal. The process was extremely frustrating because the robot does not tell you what is wrong. It's up to me to root-cause and correct. The hardest problem was boosting the wireless range. Typically wireless runs on a 2.4Ghz or 5Ghz frequency. The former has longer range, but overlapping channels, whereas the latter has short range and more bandwidth. In the university library many 2.4Ghz wireless channels were being used, which throttled the bandwidth for visualizing the robot's sensors. The solution was to choose a 5Ghz channel in the DFS radar band, no interferrence!

![UNR Library Plan](/img/thesis/at_one_inset_robot.png)

With a working robot I could finally run my experiment! Someone tipped me towards running the experiment in the library, and I formulated an interesting plan. The methodology was simple:

- Recruit students studying in the library to "interact" with my robot.
- Participants follow the robot to three stops and deliver a package at each stop.
- Study where participants deliver each package.

The last stop was in front of an emergency exit door. From my literature review I learned people were highly likely to follow a robot through an emergency exit in an evacuation. Now what would happen if they were confronted with the door while delivering a package? Given the "foot-in-the-door" effect, I was curious a risk seeking participant would open it and set off an alarm.

## Running the Experiment

I conducted the entire experiment myself. Recruiting students by walking up to them cold was a humbling experience, but I got a surprising participation rate of about 20\%. Racing to meet deadline by the end of the semester, I gathered 30 trials worth of data! No one opened the emergency exit door. "An Amazon delivery driver wouldn't open someone's door" remarked on individual. Although one reason for this is because the robot didn't talk to people, it just beeped when it reached a delivery stop. Given this limited information, people wouldn't even enter a private common room to deliver a package! So much for overtrusting the robot. A significant finding was pairs of friends would enter the common room, which concurs with other research. Labeling the packages was sufficient to prod most individuals into the common room. I didn't try too hard to force them to open the emergency exit. The purpose of this experiement was to show how much information people needed for overtrust, and the common room demonstrated small hints were sufficient to direct people. It's unclear whether the participants felt similarly uncomfortable in both conditions, an opportunity for further research.

Running the experiment was a lot of fun. I remotely operated the robot in front of every person and they did not suspect it! As the number of trials increased, I honed in the procedure, improved the data collection, and attempted to reduce variation between subjects. 

## Lessons Learned

My thesis project was not perfect, but it was mine and it was fun to execute. The biggest lesson learned is one that has served me well over my career:

> when faced with enormous obstacles, they must be comfronted or else they will destroy you.

I didn't give up when my teammates moved away, or when my advisor pressured me to produce something from nothing. I didn't give up when the robot failed to perform, or when people didn't open the emergency exit. And most importantly I didn't give up on myself. 

<img src="/img/thesis/NV_Family.jpg" alt="Family" width="200"/>

I'm thankful for my wife and dog who sherparded me through this process. Without them I would be lost, and with them I am purposeful. Looking forward to the next stage of my career!