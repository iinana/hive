cat /etc/passwd | grep -v '#' | cut -d ':' -f 1 | awk "NR%2==0" | sort -r | sed -n "$FT_LINE1, $FT_LINE2 p" | tr '\n' ', ' | sed 's/,$/./g'
