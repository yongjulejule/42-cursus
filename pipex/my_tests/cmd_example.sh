./pipex my_tests/cruella cat "awk '{printf\"%s\", \$1}'" log.log
./pipex test_parrot cat "awk 'RS=1 {for (i=0;i<10000;i++){{print \$0}}}'" dest_parrot
./pipex my_tests/test_parrot cat cat cat  "awk 'RS=1 {for (i=0;i<10000;i++){{print \$0}}}'" dest_parrot
