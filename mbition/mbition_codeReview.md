* The challenge was to perform a code review. A HR application based on c++ had a problem which had to be fixed.
* The Application could take a name and id as input from command line. And then an action command had to be provided to specify what needs to be done with the name.
* There was a struct with employee  *name and id.
```
struct employee{
  int id;
  string* name;
}
```
* There was a base class called action.
```
class Action{
public:
  virtual Action(struct* employee);

private:
  timeStampGeneratorfunc(){
    // Actual function was available which returned a time stamp.
  }
}
```
* There were two derived classes out of the base class for action.
  * New - This derived class created a new employee and saved it.
  ```
  class new : Action{
    // create new struct and save the action along with time stamp.
    virtual Action(){}
  }
  ```
  * Rename - This derived class renamed a existing employee and saved it.
  ```
  class rename : Action{
    // create new struct and save the action along with time stamp.
    virtual Action(){}
  }
  ```
* Both these derived classes had the `action` function defined as a virtual function.
* In the main function after receiving an input from the user the action is defined.
  ```
  cin >> action.
  if (action == 'n'){
    new.action(*name)
  }
  else if (action == 'r'){
    rename.action(*name)
  }
  ```