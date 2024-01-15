10 rem c64 mandelbrot set
20 gosub 200 : rem setup screen

30 rem mandelbrot algorithm (iter reduced)
40 for y=0 to 199:for x=0 to 319 : rem iterate pixels
50 xo=x*(2.47/319)-2 : yo=y*(2.24/199)-1.12 : rem mandelbrot coords
60 tx=0 : ty=0 : i=0: rem translated coords, iteration

70 if i>10 or ((tx*tx)+(ty*ty))>4 goto 110 : rem while breakout clause
80 xt=(tx*tx)-(ty*ty)+xo : rem xtemp
90 ty=(2*(tx*ty))+yo : tx=xt : i=i+1 : rem next tx,ty, iter
100 goto 70 : rem end while loop

110 if i<11 then gosub 300 : rem plot point if iter < 11
120 next x : next y
130 goto 130 : rem loop to hold screen

200 rem set screen up
201 print chr$(147) : rem clear screen
202 base=2*4096:for i=base to base+7999:poke i,0:next i:rem set and clear base
203 poke 53272,peek(53272) or 8 : rem put bitmap at 8192
204 poke 53265,peek(53265) or 32 : rem enable bitmap
205 for i=1024 to 2023:poke i,96:next i:rem set colors to blue/black
206 return

300 rem plot x,y
301 ch=int(x/8) : ro=int(y/8) : ln=y and 7 : rem char, row, line
302 by=base+ro*320+8*ch+ln : rem byte location
303 bi=7-(x and 7) : rem pixel in byte
304 poke by,peek(by) or (2^bi) : rem set bit in byte
305 return