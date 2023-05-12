# DTF_2D

### Math

- Discrete Fourier Transform
```math
F(k,l) = \displaystyle\sum\limits_{i=0}^{N-1}\sum\limits_{j=0}^{N-1} f(i,j)e^{-i2\pi(\frac{ki}{N}+\frac{lj}{N})}
```
- Euler's formula
```math
e^{ix} = \cos{x} + i\sin {x}
```

- Magnitude
```math
M = \sqrt[2]{ {Re(DFT(I))}^2 + {Im(DFT(I))}^2}
```

- Log scale
```math
M_1 = \log{(1 + M)}
```

### In
![lena](https://github.com/KuchkinAleksey/DTF_2D/assets/47223090/edb922f1-6a62-448d-a51b-2432eba91d06)

### Out ($`dt = 1`$)
![1](https://github.com/KuchkinAleksey/DTF_2D/assets/47223090/ee147ab9-c228-45c5-b246-6066085970ed)

### Out ($`dt = N/20`$)
![20](https://github.com/KuchkinAleksey/DTF_2D/assets/47223090/17064bd6-09bd-44d8-a0a5-1123e3ec57a1)
