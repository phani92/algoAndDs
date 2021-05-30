# Interview question short cuts

* Find an element in a vector:
  ```
  if ( std::find(vec.begin(), vec.end(), item) != vec.end() )
   do_this();
  else
   do_that();
  ```
* Sort a vector:
  ```
  sort(vec.begin(), vec.end());
  ```
* Count occurrence of a character in a string
  ```
  std::count( temp.begin(), temp.end(), 'a' ) ;
  ```
