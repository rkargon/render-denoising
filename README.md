# CS224 Final Project &mdash; Render Denoising

Loudon Cohen & Raphael Kargon

[Link to Github repo](https://github.com/loudonclear/cs224final) (**note**: use branch `temporal-history`)

## Features

 - Separation of albedo, direct lighting, and indirect lighting channels
 - Spatial wavelet filtering -- taking into account normals, color edges, and depth/world-position differences
 - Temporal accumulation -- Accumulation of color from previous frames, and variance estimation (to improve edge blurring).
 - Motion vectors -- reprojection to match up points across frames, even w/ movement.
 - Fast approximate anti-aliasing

## Known Issues

 - Reflections and refractions can be blurry (esp. on flat surfaces)
 - Temporal history works, but "history length" parameter seems stuck at one, making it difficult to add improvements to areas w/ no history (e.g. spatial variance estimation)

## Usage
```
 mkdir build && cd build
 qmake -makefile ../final.pro
 make release
 ./release/final <scene xml>
./release/final -h (for more options)
```

## Sample Images

![results1](res/cornell demo.png)

![results2](res/svgf2.png)
