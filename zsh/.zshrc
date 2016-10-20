# Path to your oh-my-zsh installation.
export ZSH=/home/acg/.oh-my-zsh

#xrdb ~/.Xdefaults
# Set name of the theme to load.
# Look in ~/.oh-my-zsh/themes/
# Optionally, if you set this to "random", it'll load a random theme each
# time that oh-my-zsh is loaded.
ZSH_THEME="bold_arrow"
# ZSH_THEME="avit"
# ZSH_THEME="cloud"

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion. Case
# sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# The optional three formats: "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load? (plugins can be found in ~/.oh-my-zsh/plugins/*)
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git web-search ssh-agent)

# User configuration

export PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games"
# export MANPATH="/usr/local/man:$MANPATH"

source $ZSH/oh-my-zsh.sh
source $HOME/.zsh/.ttycolors


# You may need to manually set your language environment
export LANG=en_GB.utf-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# ssh
# export SSH_KEY_PATH="~/.ssh/dsa_id"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

export TERM=rxvt-256color

##
## ALIASES
##

## Change this between computers
alias dev='cd ~/dev'
alias blog='cd ~/dev/albertocg.github.io'
alias repos='cd ~/Documents/Dev/GitRepos'
alias startx='ssh-agent startx'

alias ll='ls -lhA'
alias ls='ls --color=auto'
alias ..='cd ..'

alias c='clear'

alias reboot='sudo reboot'
alias syssuspend='systemctl suspend && lock'

# requires pandoc
alias tohtml='pandoc -t html -o' 
alias tomd='pandoc -t markdown_github -o' 
alias todocx='pandoc -t docx -o' 
alias topdf='pandoc -t latex -o'

## Fedora specific install
alias install='sudo dnf install'


alias shrc='nvim ~/.bashrc'
alias zshrc='nvim ~/.zshrc'
alias omzrc='nvim ~/.oh-my-zsh'
alias shalias='nvim ~/.bash_aliases'
alias shrl='. ~/.bashrc'
alias zshrl='. ~/.zshrc'
alias mux='nvim ~/.tmux.conf'
alias vimrc='nvim ~/.vimrc'
alias vim='nvim'

alias s='. ~/.tmux_session.sh'
alias muxkill='tmux kill-session -t'
alias muxses='tmux ls'
eval $(thefuck --alias)

man() {
    env \
        LESS_TERMCAP_mb=$'\e[01;31m' \
        LESS_TERMCAP_md=$'\e[01;31m' \
        LESS_TERMCAP_me=$'\e[0m' \
        LESS_TERMCAP_se=$'\e[0m' \
        LESS_TERMCAP_so=$'\e[01;44;33m' \
        LESS_TERMCAP_ue=$'\e[0m' \
        LESS_TERMCAP_us=$'\e[01;32m' \
        man "$@"
}

export EDITOR='nvim'

export PYTHONUSERBASE="$HOME/local"

export PATH="$HOME/local/bin:$HOME/.cargo/bin:$PATH"
export MAIL="$HOME/var/mail/INBOX"
export VISUAL="nvim"

export NVM_DIR="/home/acg/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh"  # This loads nvm

export PATH="$PATH:$HOME/.rvm/bin" # Add RVM to PATH for scripting
title FSociety

if ! pgrep -u $USER ssh-agent > /dev/null; then
    ssh-agent > ~/.ssh-agent-thing
fi
if [[ "$SSH_AGENT_PID" == "" ]]; then
    eval $(<~/.ssh-agent-thing)
fi

export XDG_CONFIG_HOME="$HOME/.config"
