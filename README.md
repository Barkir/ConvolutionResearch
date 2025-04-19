# Covolutional Neural Networks
- I created this repo to collect all the information about convolutional neural networks and make it as easy to understand as it is possible.


## What is convolution?

It is mainly a discrete sum of composition of two functions shifted relative to each other



$$
(f*g)[n] = \sum_{m=-\infty}^{\infty} f[m]g[n-m]
$$

$$
Y_{i, k} = \sum_{c=1}^{C}{D_{i, c} \cdot G_{k, c}}
$$

- **K** filters
- **C** channels
- **R * S** - size of mini-batch
- **G** - filter elements
- **D** - image elements

![image](readme_img/conv_anim.gif)

Mainly we just convert one matrix to other using **Kernel** matrix. This picture shows us an example of **sharpening kernel**. It multiplies the central pixel by 5 and subtract the neighbors.

### Convolution parameters

1. Padding - expansion of the input signal. Used for edge processing.
- Zero padding (edges are filled with zeros)
- Valid padding (no padding)
- Reflect padding (edges are filled with thei reflection of the pixels on the image)

![image](readme_img/padding.gif)

2. Stride - a step of convolution


![alt text](readme_img/stride.gif)

1. Dilation - step between elements.

![image](readme_img/dilation.gif)


## Fast algorithms

### FIR filter

Multiplications required
$
\mu(F(m, r)) = m + r - 1
$

$F(2, 3) = \begin{bmatrix}
d0 & d1 & d2 \\
d1 & d2 & d2
\end{bmatrix}$ $\begin{bmatrix}
g0 \\
g1 \\
g2 \\
\end{bmatrix}$=$\begin{bmatrix}
m1+m2+m3 \\
m2 -m3 - m4
\end{bmatrix}$

where

$m1 = (d0-d2)g0 \ \ \ m2 = (d1+d2)\frac{g0+g1+g2}{2}$


$m4 = (d1-d3)g2 \ \ \ m3 = (d2-d1) \frac{g0-g1+g2}{2}$

## Winograd algorithm
We move the input mat to other space, where we can replace convolution to Hadamard product (element by element composition)

$P = N[H/m][W/m]$ is the number of image tiles $\alpha = m + r - 1$ is the input tile size.

Neighboring tiles overlap by r-1
$G, B^T, A^T$ ar filter, data and inverse transforms.

```
for k = 0 to K do
    for c = 0 to C do
        u = G_g(k,c)G^T \in R^{a x a}
        Scatter u to matrices U: U_{k,c}^{\xi, \nu} = u_{\xi, \nu}

for b = 0 to P do
    for c = 0 to C do
        v = B^T d_{c, b} B \in R^{a x a}

for \xi = 0 to \alpha do
    for \nu = 0 to \alpha do
    M^(\xi, \nu) = U^{\xi, \nu} * V^{\xi, \nu}

for k = 0 to K do
    for b = 0 to P do
        Gather m from matrices M: m_{\xi, \nu} = M_{k, b}^{\xi, \nu}
        Y_{k, b} = A^TmA
```




## P.S
[Michael Nilsen Book about AI](http://neuralnetworksanddeeplearning.com/about.html)
