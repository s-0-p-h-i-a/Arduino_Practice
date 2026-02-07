## ✍️ Dev Log — 14–15 June 2025

### 🔧 14/06

- Initial idea: select one of 3 LEDs via serial input
    
- 1st attempt failed due to wiring issues and `Serial.read()` misuse
    
- Rewiring + blink test confirmed hardware worked
    
- Switched from `int` to `char` input, then used `toInt()` conversion
    
- Learned that `Serial.read()` handles single char and doesn’t auto-parse newlines
    
- Introduced input validation with `validInput` flag
    
- Noticed input lag issues: program misread newline as extra input


### 🧪 15/06

- Changed program feedback from showing number to showing color name
    
- Initial attempt using C++ strings was overcomplicated
    
- Used direct `Serial.print()` for simple, robust messaging
    
- Confirmed LED turns off at end of each loop (not needed mid-loop)

---

Note: This dev log was drafted using my raw development notes and code, with AI-assisted formatting and polish. All content was reviewed for accuracy. For a full description of the documentation process and AI use, see the README.