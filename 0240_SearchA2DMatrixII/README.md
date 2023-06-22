# 240. Search a 2D Matrix II

can't pass 2D as funxtion argument "int** matrix" <br/>

## C_1 
1) check targe if in the row by each row <br/>
2) find targe in that row <br/>

## C_2 Binary search
same as C_1, but using binary search in step 2 <br/>

## C_3 
start from bottom left, <br/>
if target > matrix[row][col] => right shrift <br/>
if target < matrix[row][col] => up shrift <br/>