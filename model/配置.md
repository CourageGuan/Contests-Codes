title: 配置
toc: true
date: 2015-06-02 17:15:37
categories: Tips
---

##Vim

###Easy
	colo desert 
	syntax on
	set nu cin mouse=a
	set ts=4 sw=4
	set guifont=DejaVuSans\Mono\ 12 "字体
	"set guifont=consolas: h12 "For Win

	"F9编译运行
	map <F9> :call CR()<CR>
	func! CR()
	exec "w"
	exec "!g++ -O2 -g  % -o %<"
	exec "! ./%<"	"windows改成 exec "! %<"
	endfunc
	

###Full
	colo desert 
	syntax on
	set nu
	set history=1000000
	set tabstop=4 
	set shiftwidth=4
	set smarttab
	set cindent
	set nobackup
	set noswapfile
	set mouse=a
	set incsearch
	set hlsearch 
	let &termencoding=&encoding 
	set fileencodings=utf-8,gbk 
	filetype on 
	filetype plugin on 
	filetype indent on
	
	
	set guifont=DejaVuSans\Mono\ 12 "字体
	"set guifont=courier_new:h12 "For Win
	set shortmess=atI   " 关闭启动提示 
	winpos 400 400      " 设定窗口位置  
	set lines=60 columns=100    " 设定窗口大小  
	set guioptions-=T           " 隐藏工具栏
	set guioptions-=m           " 隐藏菜单栏
	set laststatus=2 " 显示状态栏 (默认值为 1, 无法显示状态栏)
	set statusline=[%n]%<%f%y%h%m%r%=\ %l\ of\ %L,%c "设置在状态行显示的信息
	
	 "改变光标形状
	if has("autocmd")
	  au InsertEnter * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape ibeam"
	    au InsertLeave * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape block"
		  au VimLeave * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape ibeam"
	endif
	
	" Source a global configuration file if available
	if filereadable("/home/.vim/vimrc")
	  source /home/.vim/vimrc 
	endif
	
	"F9编译运行
	map <F9> :call CR()<CR>
	func! CR()
	exec "w"
	exec "!g++ -O2 -g  % -o %<"
	exec "! ./%<"	"windows改成 exec "! %<"
	endfunc
	
	"F8 Python
	map <F8> :call PY()<CR>
	func! PY()
	exec "w"
	exec "!python %<.py"
	endfunc
	 
	imap <c-]> {<cr>}<c-o>O<left><right>
	map <C-A> ggVG"+y
	
	"imap <c-]> {<cr>}<c-o>O<left><right>
	"inoremap (()<LEFT>
	"inoremap [[]<LEFT>
	"inoremap {{}<LEFT>
	"inoremap """<LEFT>
	"inoremap '''<LEFT>
	
	"F2插入模板
	map <F2> :call SetTitle()<CR>
	func SetTitle()
	let l = 0
	let l = l + 1 | call setline(l, '/*')
	let l = l + 1 | call setline(l, ' & Created Time:  '.strftime('%c'))
	let l = l + 1 | call setline(l, ' & File Name: '.expand('%'))
	let l = l + 1 | call setline(l, ' & Author: NoBystander')
	let l = l + 1 | call setline(l, '*/')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '//#pragma comment(linker, "/STACK:1024000000,1024000000")')
	let l = l + 1 | call setline(l, '//#include <bits/stdc++.h>')
	let l = l + 1 | call setline(l, '#include <iostream>')
	let l = l + 1 | call setline(l, '#include <stdio.h>')
	let l = l + 1 | call setline(l, '#include <string.h>')
	let l = l + 1 | call setline(l, '#include <ctype.h>')
	let l = l + 1 | call setline(l, '#include <math.h>')
	let l = l + 1 | call setline(l, '#include <stdlib.h>')
	let l = l + 1 | call setline(l, '#include <time.h>')
	let l = l + 1 | call setline(l, '#include <algorithm>')
	let l = l + 1 | call setline(l, '#include <vector>')
	let l = l + 1 | call setline(l, '#include <set>')
	let l = l + 1 | call setline(l, '#include <map>')
	let l = l + 1 | call setline(l, '#include <string>')
	let l = l + 1 | call setline(l, '#include <queue>')
	let l = l + 1 | call setline(l, '#include <stack>') 
	let l = l + 1 | call setline(l, '#include <list>')
	let l = l + 1 | call setline(l, '#include <utility>')
	let l = l + 1 | call setline(l, 'using namespace std;')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '#define LEN(n) (int)log10(n)+1')
	let l = l + 1 | call setline(l, '#define REP(i,n) for(int i=0;i<n;++i)')
	let l = l + 1 | call setline(l, '#define F(i,a,b) for(int i=a;(i)<b;++i)')
	let l = l + 1 | call setline(l, '#define Fd(i,b,a) for(int i=b-1;i>=a;--i)')
	let l = l + 1 | call setline(l, '#define EACH(i,a) for(__typeof((a).begin()) i=a.begin(); i!=a.end(); ++i)')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '#define FILL(a,t) memset((a),(t),sizeof(a))')
	let l = l + 1 | call setline(l, '#define CLEAR(ST) while(!ST.empty()) ST.pop();')
	let l = l + 1 | call setline(l, '#define all(a) a.begin(),a.end()')
	let l = l + 1 | call setline(l, '#define sz(a) ((int)(a).size())')
	let l = l + 1 | call setline(l, '#define lowbd(a,x) lower_bound(all(a),x) - a.begin()')
	let l = l + 1 | call setline(l, '#define upbd(a,x) upper_bound(all(a),x) - a.begin()')
	let l = l + 1 | call setline(l, '#define pb push_back')
	let l = l + 1 | call setline(l, '#define mp(A,B) make_pair(A,B)')
	let l = l + 1 | call setline(l, '#define fi first')
	let l = l + 1 | call setline(l, '#define se second')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'typedef long long LL;')
	let l = l + 1 | call setline(l, 'typedef unsigned long long ULL;')
	let l = l + 1 | call setline(l, 'typedef double DB;')
	let l = l + 1 | call setline(l, 'typedef long double LDB;')
	let l = l + 1 | call setline(l, 'typedef vector<int> VI;')
	let l = l + 1 | call setline(l, 'typedef map<string,int> MSI;') 
	let l = l + 1 | call setline(l, 'typedef map<int,int> MII;')
	let l = l + 1 | call setline(l, 'typedef pair<int,int> PII;')
	let l = l + 1 | call setline(l, '#define priority_queue PQ')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '//#define DEBUG')
	let l = l + 1 | call setline(l, '#ifdef DEBUG')
	let l = l + 1 | call setline(l, '	#define debug(args...) do{cerr<<#args<<":"; dbg,args; cerr<<endl;}while(0) ')
	let l = l + 1 | call setline(l, '	#define OK puts("OK")')
	let l = l + 1 | call setline(l, '	#define C(a) cout<<"~~"<<a<<"~~"<<endl')
	let l = l + 1 | call setline(l, '	#define PM(a,x,y) F(i,0,x){F(j,0,y) cout<<a[i][j]<<" ";cout<<endl;} ')
	let l = l + 1 | call setline(l, 'struct debugger{')
	let l = l + 1 | call setline(l, '	template<typename T> debugger& operator , (const T& v){')
	let l = l + 1 | call setline(l, '		cerr<<v<<" ";')
	let l = l + 1 | call setline(l, '		return *this;')
	let l = l + 1 | call setline(l, '	}')
	let l = l + 1 | call setline(l, '} dbg;')
	let l = l + 1 | call setline(l, '#else')
	let l = l + 1 | call setline(l, '	#define debug(args...)')
	let l = l + 1 | call setline(l, '	#define OK')
	let l = l + 1 | call setline(l, '	#define C(a)')
	let l = l + 1 | call setline(l, '	#define PM(a,x,y)')
	let l = l + 1 | call setline(l, '#endif')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'const int INF = 0x3f3f3f3f;')
	let l = l + 1 | call setline(l, 'const LL  LINF = 0x3f3f3f3f3f3f3f3fLL;')
	let l = l + 1 | call setline(l, 'const DB EPS = 1e-9;')
	let l = l + 1 | call setline(l, 'const DB PI = acos(-1.0);')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'const int dx[] = {-1, 0, 1, 0};')
	let l = l + 1 | call setline(l, 'const int dy[] = {0, 1, 0, -1};')
	let l = l + 1 | call setline(l, 'const int mv[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'LL nextInt(){')
	let l = l + 1 | call setline(l, '	char ch=getchar();')
	let l = l + 1 | call setline(l, '	while(!isdigit(ch)) ch=getchar();')
	let l = l + 1 | call setline(l, '	LL res=0;')
	let l = l + 1 | call setline(l, '	while(isdigit(ch)){')
	let l = l + 1 | call setline(l, '		res=res*10+ch-48;')
	let l = l + 1 | call setline(l, '		ch=getchar();')
	let l = l + 1 | call setline(l, '	}')
	let l = l + 1 | call setline(l, '	return res;')
	let l = l + 1 | call setline(l, '}')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'void write(LL x){')
	let l = l + 1 | call setline(l, '	if(x>9) write(x/10);')
	let l = l + 1 | call setline(l, '	putchar(x%10+48);')
	let l = l + 1 | call setline(l, '}')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '/*-----  on ne voit bien qu avec le coeur.l essentiel est invisible pour les yeux  -----*/')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'void init()')
	let l = l + 1 | call setline(l, '{')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '}')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'void solve()')
	let l = l + 1 | call setline(l, '{')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '}')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'int main()')
	let l = l + 1 | call setline(l, '{')
	let l = l + 1 | call setline(l, '	//freopen("test.txt","r",stdin);')
	let l = l + 1 | call setline(l, '	//freopen("out.txt","r",stdout);')
	let l = l + 1 | call setline(l, '	//ios::sync_with_stdio(false);')
	let l = l + 1 | call setline(l, '	//cin.tie(0);')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '	//printf("\nTIME WASTED  %.2f s\n",(double)clock()/CLOCKS_PER_SEC);')
	let l = l + 1 | call setline(l, '    return 0;')
	let l = l + 1 | call setline(l, '}')
	let l = l + 1 | call setline(l, '')
	endfunc
	map <F3> :call Maker()<CR>
	func Maker()
	let l = 0
	let l = l + 1 | call setline(l, '#include <iostream>')
	let l = l + 1 | call setline(l, '#include <cstdio>')
	let l = l + 1 | call setline(l, '#include <ctime>')
	let l = l + 1 | call setline(l, '#include <cstdlib>')
	let l = l + 1 | call setline(l, '#include <string>')
	let l = l + 1 | call setline(l, 'using namespace std;')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, 'int main()')
	let l = l + 1 | call setline(l, '{')
	let l = l + 1 | call setline(l, '	srand(time(0));')
	let l = l + 1 | call setline(l, '	freopen("test","w",stdout);')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '')
	let l = l + 1 | call setline(l, '	return 0;')
	let l = l + 1 | call setline(l, '}')
	endfunc


##Terminal

	# ~/.bashrc: executed by bash(1) for non-login shells.
	# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
	# for examples
	
	# If not running interactively, don't do anything
	case $- in
	    *i*) ;;
	      *) return;;
	esac
	
	# don't put duplicate lines or lines starting with space in the history.
	# See bash(1) for more options
	HISTCONTROL=ignoreboth
	
	# append to the history file, don't overwrite it
	shopt -s histappend
	
	# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
	HISTSIZE=1000
	HISTFILESIZE=2000
	
	# check the window size after each command and, if necessary,
	# update the values of LINES and COLUMNS.
	shopt -s checkwinsize
	
	# If set, the pattern "**" used in a pathname expansion context will
	# match all files and zero or more directories and subdirectories.
	#shopt -s globstar
	
	# make less more friendly for non-text input files, see lesspipe(1)
	[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"
	
	# set variable identifying the chroot you work in (used in the prompt below)
	if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
	    debian_chroot=$(cat /etc/debian_chroot)
	fi
	
	# set a fancy prompt (non-color, unless we know we "want" color)
	case "$TERM" in
	    xterm-color) color_prompt=yes;;
	esac
	
	# uncomment for a colored prompt, if the terminal has the capability; turned
	# off by default to not distract the user: the focus in a terminal window
	# should be on the output of commands, not on the prompt
	#force_color_prompt=yes
	
	if [ -n "$force_color_prompt" ]; then
	    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
		# We have color support; assume it's compliant with Ecma-48
		# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
		# a case would tend to support setf rather than setaf.)
		color_prompt=yes
	    else
		color_prompt=
	    fi
	fi
	
	if [ "$color_prompt" = yes ]; then
	    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
	else
	    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
	fi
	unset color_prompt force_color_prompt
	
	# If this is an xterm set the title to user@host:dir
	case "$TERM" in
	xterm*|rxvt*)
	    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
	    ;;
	*)
	    ;;
	esac
	
	# enable color support of ls and also add handy aliases
	if [ -x /usr/bin/dircolors ]; then
	    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
	    alias ls='ls --color=auto'
	    #alias dir='dir --color=auto'
	    #alias vdir='vdir --color=auto'
	
	    alias grep='grep --color=auto'
	    alias fgrep='fgrep --color=auto'
	    alias egrep='egrep --color=auto'
	fi
	
	# some more ls aliases
	alias ll='ls -alF'
	alias la='ls -A'
	alias l='ls -CF'
	
	# Add an "alert" alias for long running commands.  Use like so:
	#   sleep 10; alert
	alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
	
	# Alias definitions.
	# You may want to put all your additions into a separate file like
	# ~/.bash_aliases, instead of adding them here directly.
	# See /usr/share/doc/bash-doc/examples in the bash-doc package.
	
	
	if [ -f ~/.bash_aliases ]; then
	    . ~/.bash_aliases
	fi
	
	# enable programmable completion features (you don't need to enable
	# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
	# sources /etc/bash.bashrc).
	if ! shopt -oq posix; then
	  if [ -f /usr/share/bash-completion/bash_completion ]; then
	    . /usr/share/bash-completion/bash_completion
	  elif [ -f /etc/bash_completion ]; then
	    . /etc/bash_completion
	  fi
	fi
	
	# Own Define
	alias rm='rm -i'
	alias mv='mv -i'
	alias cp='cp -i'
	alias clr='clear'
	alias md='mkdir'
	alias cda='cd ~/ACM/'
	alias cdd='cd ~/Desktop/'
	alias py='python'
	alias cb='codeblocks'
	alias cdn='cd ~/Website/nobystander.github.io/'
	alias cdt='cd ~/Website/nobystander.github.io/source/_posts/'
	alias fin='python ~/Desktop/find.py'
	alias chrome='/opt/google/chrome/./chrome'
	alias eclipse='/opt/eclipse/./eclipse'
	alias nutstore='~/.nutstore/dist/bin/./nutstore-pydaemon.py'
	alias gui='nautilus .'
	alias unzip='unzip -O CP936'
	
	export NVM_DIR="/home/alex/.nvm"
	[ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh"  # This loads nvm
	
	# texlive
	PATH=/usr/local/texlive/2014/bin/x86_64-linux:$PATH; export PATH
	MANPATH=/usr/local/texlive/2014/texmf-dist/doc/man:$MANPATH; export MANPATH
	INFOPATH=/usr/local/texlive/2014/texmf-dist/doc/info:$INFOPATH; export INFOPATH

