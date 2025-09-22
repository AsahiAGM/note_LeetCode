#!/bin/bash
setlang () 
{ 
    lang="$1"
    probname="$2"
    cd "$lang" && touch "main.$lang" "$probname.$lang"
}
solution () 
{ 
    cd problems
    mkdir "$1" && cd "$1" && mkdir c cpp cs py rust go
}
fsolution()
{
    cd problems
    mkdir "$1" && cd "$1" && mkdir c cpp cs py rust go
    setlang "$2" "$3"
}