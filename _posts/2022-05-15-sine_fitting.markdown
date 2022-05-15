---
layout: post
title:  "Sine Fitting"
date:   2022-05-14 8:08:16 -0700
categories: data_fitting
usemathjax: true
---

![Sine curve sampled with noise.](/img/fitting/sine_data.png){:class="img-responsive"}

Sine signals are not lines. So how does a *linear* model fit a sine curve? Do nonlinear models work better? Let's try 10 different methods of modeling a sine curve.

## 1. A line

Straight lines are be defined by two numbers, slope $m$ and intercept $b$. Given some input $x$, the output is

$$
y = mx + b.
$$

## 2. Piecewise lines
