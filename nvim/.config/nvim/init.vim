set nocompatible
scriptencoding utf-8
filetype off

call plug#begin('~/.config/nvim/plugged')
Plug 'scrooloose/syntastic'
Plug 'ervandew/supertab'
Plug 'tomtom/tcomment_vim'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'jiangmiao/auto-pairs'
Plug 'Valloric/YouCompleteMe', { 'do': './install.py' }
Plug 'airblade/vim-gitgutter'

call plug#end()

filetype plugin indent on

let mapleader = " "

" ===== PERSONAL =====
set background=dark
colorscheme contrastneed

set number
set numberwidth=4
syn on

set incsearch
set ruler
set noswapfile

"Case insensitive
set ignorecase
set smartcase

"Soft tabs
set tabstop=4
set shiftwidth=4
set shiftround
set expandtab
set smarttab

" Splits autoresize
set winwidth=84
set winheight=5
set winminheight=5
set winheight=999

"Line 80 mark
set textwidth=0
set colorcolumn=+1
highlight ColorColumn ctermbg=1

set wrap
set linebreak
set nolist

set wrapmargin=0
set formatoptions-=t

set showcmd

autocmd BufEnter * silent! cd %:p:h
autocmd BufWinLeave *.* mkview
autocmd BufWinEnter *.* silent loadview"

set laststatus=2

" ==== MOVEMENT ====
nnoremap <C-j> <C-a>j
nnoremap <C-k> <C-a>k
nnoremap <C-l> <C-a>l
nnoremap <C-h> <C-a>h
" inoremap jk <Esc>

map <C-tab> :bn

" == SCROLLING ==
set scrolloff=10

" ==== RELATIVE NUMBERING====
set rnu
function! ToggleNumbersOn()
  set nu!
  set rnu
endfunction
function! ToggleRelativeOn()
  set rnu!
  set nu
endfunction
autocmd FocusLost * call ToggleRelativeOn()
autocmd FocusGained * call ToggleRelativeOn()
autocmd InsertEnter * call ToggleRelativeOn()
autocmd InsertLeave * call ToggleNumbersOn()

" ===== SYSTEM COPY & PASTE SUPPORT =====
vmap <F6> :!xclip -f -sel clip<CR>
map <F7> :r!xclip -o -sel clip<CR>

"==== NERDTree ====
map <C-n> :NERDTreeToggle<cr>

" ==== CtrlP ====
let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlP'
let g:ctrlp_working_path_mode = 'ra'


" ===== Syntastic =====

let g:syntastic_error_symbol='✗'
let g:syntastic_warning_symbol='⚠'
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

" ==== vim closetag =====
let g:closetag_filenames = "*.html,*.xhtml,*.phtml"

set t_Co=256
