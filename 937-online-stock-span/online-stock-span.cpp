

class StockSpanner {
public:
    // Stack stores pairs: {price, span}
    std::stack<std::pair<int, int>> s;

    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
        // While the stack is not empty and the top price is 
        // less than or equal to the current price
        while (!s.empty() && s.top().first <= price) {
            // Add the span of the previous price to the current span
            span += s.top().second;
            s.pop();
        }
        
        // Push the current price and its calculated span onto the stack
        s.push({price, span});
        
        return span;
    }
};