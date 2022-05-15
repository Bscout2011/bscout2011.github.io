---
layout: post
title:  "Welcome to Jekyll!"
date:   2022-05-13 18:08:16 -0700
categories: jekyll update
usemathjax: true
---

This blog will showcase all the math and visualisations I learn in my free time. This post documents perculiarities setting up Jekyll.

Jekyll is a static content website generator built with Ruby. A `gem` is a Ruby package. A `Gemfile` stores Ruby packages requirements to build the website. Running `bundle exec jekyll serve` searches for the `Gemfile`, fetch-builds depdendencies, then serves the jekyll website locally at `http://127.0.0.1:4000/`. This site is cloned from the [Minimal theme](https://github.com/mmistakes/minimal-mistakes).

Page content can be written in Markdown or HTML. I like writing Markdown because it works natively with VS-Code and supports $\LaTeX$. [Jekyll](https://www.markdownguide.org/tools/jekyll/) uses kramdown to convert `.markdown` or `.md` documents into HTML. Strengths using Markdown are easy style formatting in a text editor, like *emphasis*, **strong**, `code`. Math typesetting requires including the [MathJax CDN](http://webdocs.cs.ualberta.ca/~zichen2/blog/coding/setup/2019/02/17/how-to-add-mathjax-support-to-jekyll.html). I like writing \\$x=y^2\\$ to produce $x=y^2$, but this is not enabled by [default](https://tex.stackexchange.com/questions/27633/mathjax-inline-mode-not-rendering). Some weaknesses with Markdown are images and tables. If you want an image a certain size only an HTML tag can style it. Table styling, such as removing borders, is something I will have to practice with CSS.
