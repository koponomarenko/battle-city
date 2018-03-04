# battle-city
Video game

## TODO:
- Maybe use more QML
  - Read and learn Qt Quick (another name for QML)
- Rename this function: setSpeed -> getSpeed
- Delete all memory allocated with `new`
  - Delete Timer
  - Currently there are memory leaks
- Handle exceptions in constructor
- Append '\_' to the end of class members names
- Maybe use forward declaration
- Reduce number of Timers
  - Maybe don't create them one per bullet
- Think about main loop or something similar
  - Maybe a few different timers to reflect different speeds in the game
- Think about object management
  - Who is responsible for objects life?
  - Objects memory management
  - `delete this` should be used only on dynamic objects (pattern 'factory method')
  - The class should be impossible to construct on the stack or static memory, which means a private constructor and a factory method which is a friend.
