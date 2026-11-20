"""Makes the reference outputs in examples/output from examples/input.

Run from the project root:  python3 docs/make_reference_outputs.py
Needs: pip install pillow numpy scipy
These images are what your C++ filters should match (small differences in
blur and grayscale are normal depending on the formula you use).
"""
import os
import numpy as np
from PIL import Image
from scipy.ndimage import uniform_filter

IN, OUT = "examples/input/", "examples/output/"
FLIP_ONLY_FOR = {"flip_parrot", "odd_size_staircase"}

def clamp(a): return np.clip(a, 0, 255).astype(np.uint8)
def red(a):   b = a.copy(); b[..., 1:] = 0; return b
def green(a): b = a.copy(); b[..., [0, 2]] = 0; return b
def blue(a):  b = a.copy(); b[..., :2] = 0; return b
def gray(a):
    g = clamp(a[..., 0]*0.299 + a[..., 1]*0.587 + a[..., 2]*0.114)
    return np.stack([g, g, g], -1)
def invert(a): return 255 - a
def bright(d): return lambda a: clamp(a.astype(int) + d)
def blue_blur(a):
    b = a.copy()
    b[..., 2] = clamp(uniform_filter(a[..., 2].astype(float), size=11, mode="nearest"))
    return b

filters = {"red_only": red, "green_only": green, "blue_only": blue,
           "grayscale": gray, "invert": invert,
           "brightness_plus50": bright(50), "brightness_minus50": bright(-50),
           "blue_blur": blue_blur}
flips = {"flip_horizontal": lambda a: a[:, ::-1], "flip_vertical": lambda a: a[::-1]}

for f in sorted(os.listdir(IN)):
    stem = f.rsplit(".", 1)[0]
    a = np.array(Image.open(IN + f).convert("RGB"))
    os.makedirs(OUT + stem, exist_ok=True)
    ops = dict(filters)
    if stem in FLIP_ONLY_FOR:
        ops.update(flips)
    for name, fn in ops.items():
        Image.fromarray(np.ascontiguousarray(fn(a))).save(f"{OUT}{stem}/{stem}_{name}.png")
