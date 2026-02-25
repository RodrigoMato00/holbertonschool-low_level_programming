break sample.c:81
commands
silent
printf "0x%08X\n", x
continue
end
break sample.c:86
commands
silent
printf "0x%08X\n", x
continue
end
break sample.c:103
commands
silent
if i == 0
  printf "0x%08X\n", acc
end
continue
end
run < /tmp/gdb_in
quit
