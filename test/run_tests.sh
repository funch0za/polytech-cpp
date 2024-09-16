echo "5 1 2 3 4 5" > test.txt && ./avl-tree < test.txt
echo "1" > test.txt && ./avl-tree < test.txt
echo "3 -2 -3 1" > test.txt && ./avl-tree < test.txt
echo "5 5 4 3 2 1" > test.txt && ./avl-tree < test.txt
echo "4 4984 77 -2 99" > test.txt && ./avl-tree < test.txt
echo "10 1 2 3 4 -3 2 -4 -100 99 98" > test.txt && ./avl-tree < test.txt
echo "8 -1 2 -3 40 -34 89 102 103" > test.txt && ./avl-tree < test.txt
echo "3 102 21 108" > test.txt && ./avl-tree < test.txt
echo "5 5 5 5 5 5" > test.txt && ./avl-tree < test.txt
echo "9 777 108 21 228 102 2021 -77 -3 0" > test.txt && ./avl-tree < test.txt

rm -f test.txt
