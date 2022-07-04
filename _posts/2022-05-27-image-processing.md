---
layout: post
title:  "Image Processing for Dummies"
date:   2023-05-27 7:00:00 -0700
categories: image-processing numpy PIL
usemathjax: true
---
<style>
.imgborder {
    border: 5px solid #555;
}
.center {
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 256;
}
.color-box {
    width: 10px;
    height: 10px;
    display: inline-block;
    background-color: #000;
    border: 1px solid gray;
    left: 5px;
    top: 5px;
}

</style>

<img src="/img/img_proc/pi.png" alt="Pi" class="center imgborder">

## Digital Images

An image on a computer is just a 2-dimensional matrix of numbers. A simple $8 \times 9$ image can be represented as

$$
\begin{bmatrix}
  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1 \\
  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1 \\
  1  &  1  &  0  &  0  &  0  &  0  &  0  &  1  &  1 \\
  1  &  1  &  1  &  0  &  1  &  1  &  0  &  1  &  1 \\
  1  &  1  &  1  &  0  &  1  &  1  &  0  &  1  &  1 \\
  1  &  1  &  1  &  0  &  1  &  1  &  0  &  1  &  1 \\
  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1 \\
  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1  &  1 
\end{bmatrix}
$$

where $0$ is <span class="color-box"></span> and $1$ is <span class="color-box" style="background-color: #fff"></span>. Modern smartphones capture images with thousands of pixels and arranged in Red-Green-Blue matrices.

<img src="/img/about/poppy.jpg" alt="Corgi" class="center imgborder">

Observe the fine details in this long image of a corgi. There are 2,736,370 pixels (2.7 Mega Pixels (MP)) in a $(2015, 1358)$ matrix. Zooming in reveals the discrete values.

<img src="/img/img_proc/poppy_zoom.gif" class="center imgborder">

Visualizing the entire image as a matrix is not intuitive. A useful hueristic is to examine the image histogram.

<img src="/img/img_proc/poppy_histogram.png" class="center">

Color images have 3 matrices representing Red-Green-Blue color hues for each pixel. Usually there are 256 different hues available. A histogram counts the number of pixels with a certain hue for each color channel. Examining the corgi histogram reveals the dominant colors in the image. The image has modes across

<img src="/img/img_proc/poppy_hist_modes.png" class="center">
