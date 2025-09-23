#!/bin/bash
setlang () 
{ 
    echo "  setlang..."
    lang="$1"
    probname="$2"
    cd "$lang" && touch "main.$lang" "$probname.$lang"
}
solution () 
{ 
    echo "  solution..."
    cd problems
    mkdir "$1" && cd "$1" && mkdir c cpp cs py rust go
}
fsolution()
{
    echo "fsolution..."
    solution "$1"
    setlang "$2" "$3"
    cd ../../..
}