find -name $1 -exec grep --no-filename '#include *' {} \; | wc -l 
