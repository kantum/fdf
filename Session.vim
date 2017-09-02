let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/depots/fdf
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 srcs/main.c
badd +0 srcs/parser.c
badd +1 srcs/show.c
badd +0 term://.//4667:/bin/zsh
argglobal
silent! argdel *
argadd srcs/main.c
argadd srcs/parser.c
argadd srcs/show.c
edit srcs/main.c
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=1 winminwidth=1 winheight=1 winwidth=1
exe '1resize ' . ((&lines * 85 + 52) / 105)
exe 'vert 1resize ' . ((&columns * 132 + 199) / 398)
exe '2resize ' . ((&lines * 85 + 52) / 105)
exe 'vert 2resize ' . ((&columns * 132 + 199) / 398)
exe '3resize ' . ((&lines * 85 + 52) / 105)
exe 'vert 3resize ' . ((&columns * 132 + 199) / 398)
exe '4resize ' . ((&lines * 17 + 52) / 105)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 42) / 85)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
2argu
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 2 - ((1 * winheight(0) + 42) / 85)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
2
normal! 0
wincmd w
argglobal
3argu
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 42) / 85)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
3argu
edit term://.//4667:/bin/zsh
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 1 - ((0 * winheight(0) + 8) / 17)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 08|
wincmd w
4wincmd w
exe '1resize ' . ((&lines * 85 + 52) / 105)
exe 'vert 1resize ' . ((&columns * 132 + 199) / 398)
exe '2resize ' . ((&lines * 85 + 52) / 105)
exe 'vert 2resize ' . ((&columns * 132 + 199) / 398)
exe '3resize ' . ((&lines * 85 + 52) / 105)
exe 'vert 3resize ' . ((&columns * 132 + 199) / 398)
exe '4resize ' . ((&lines * 17 + 52) / 105)
tabnext 1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
