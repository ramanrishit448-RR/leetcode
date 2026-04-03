

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s; // Using vector as a stack for easier result conversion
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            // Collision only happens if:
            // 1. Stack is not empty
            // 2. Top of stack is moving RIGHT (+)
            // 3. Current asteroid is moving LEFT (-)
            while (!s.empty() && s.back() > 0 && ast < 0) {
                if (abs(s.back()) < abs(ast)) {
                    // Right-moving asteroid is smaller: explode it and continue
                    s.pop_back();
                    continue;
                } else if (abs(s.back()) == abs(ast)) {
                    // Both are same size: both explode
                    s.pop_back();
                }
                // If top is larger or they were equal, current asteroid is destroyed
                destroyed = true;
                break;
            }
            
            if (!destroyed) {
                s.push_back(ast);
            }
        }
        return s;
    }
};