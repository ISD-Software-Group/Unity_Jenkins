test_add : test/test_add.c src/add.c  Unity/src/unity.c
	gcc -o test_add test/test_add.c src/add.c  Unity/src/unity.c -I Unity/src/ -I src/ 