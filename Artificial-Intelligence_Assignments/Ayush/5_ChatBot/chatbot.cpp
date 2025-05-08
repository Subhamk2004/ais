#include <bits/stdc++.h>
using namespace std;

// Simple bookstore chatbot that can respond to customer inquiries

class Chatbot {
private:
    // Store common keywords and their responses
    map<string, string> responses;
    
    // Store common greeting keywords
    vector<string> greetings;
    
    // Store common exit keywords
    vector<string> exitPhrases;
    
    // Convert input to lowercase for case-insensitive matching
    string toLowerCase(const string& input) {
        string result = input;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
    
    // Check if input contains any of the keywords in the given vector
    bool containsAnyKeyword(const string& input, const vector<string>& keywords) {
        string lowercaseInput = toLowerCase(input);
        for (const string& keyword : keywords) {
            if (lowercaseInput.find(keyword) != string::npos) {
                return true;
            }
        }
        return false;
    }
    
    // Find the best matching response based on keywords in the question
    string findBestResponse(const string& question) {
        string lowercaseQuestion = toLowerCase(question);
        
        // Check for keyword matches with more specific patterns first
        if (lowercaseQuestion.find("return") != string::npos) {
            return responses["return"];
        }
        
        if (lowercaseQuestion.find("shipping") != string::npos || 
            (lowercaseQuestion.find("ship") != string::npos && lowercaseQuestion.find("cost") != string::npos)) {
            return responses["shipping"];
        }
        
        if (lowercaseQuestion.find("hour") != string::npos || 
            lowercaseQuestion.find("open") != string::npos || 
            lowercaseQuestion.find("time") != string::npos) {
            return responses["hour"];
        }
        
        // Continue with general keyword search
        for (const auto& pair : responses) {
            if (lowercaseQuestion.find(pair.first) != string::npos) {
                return pair.second;
            }
        }
        
        // If no match, return default response
        return "I'm sorry, I don't have information about that. Please ask about our books, orders, shipping, returns, or store hours.";
    }

public:
    Chatbot() {
        // Initialize response database with more specific keywords
        responses["book"] = "We have a wide selection of books across various genres. What kind of book are you looking for?";
        responses["price"] = "Our books range from $5 to $50. Bestsellers are typically $15-$25.";
        responses["hour"] = "Our online store is available 24/7. Our physical stores are open 9 AM to 9 PM Monday through Saturday, and 10 AM to 7 PM on Sundays.";
        responses["location"] = "We have stores in New York, Chicago, Los Angeles, and Seattle. Our online store ships worldwide.";
        responses["shipping"] = "Standard shipping takes 3-5 business days. Express shipping is available for next-day delivery for an additional fee.";
        responses["return"] = "Returns are accepted within 30 days of purchase with a receipt for a full refund.";
        responses["order"] = "To place an order, add items to your cart and proceed to checkout. You can check your order status in your account.";
        responses["contact"] = "You can reach our customer service at 1-800-BOOKS-24 or email at support@example.com.";
        responses["discount"] = "We offer 10% off for new customers and 15% off for orders over $100. Join our membership program for additional discounts.";
        responses["genre"] = "We have fiction, non-fiction, educational, children's books, and more. What genre are you interested in?";
        
        // Initialize greetings
        greetings = {"hello", "hi", "hey", "greetings", "good morning", "good afternoon", "good evening"};
        
        // Initialize exit phrases
        exitPhrases = {"bye", "goodbye", "exit", "quit", "end", "stop", "see you", "thanks bye", "thank you bye"};
    }
    
    // Process user input and generate a response
    string getResponse(const string& input) {
        string lowercaseInput = toLowerCase(input);
        
        // Check if input is a greeting
        if (containsAnyKeyword(lowercaseInput, greetings)) {
            return "Hello! Welcome to BookStore customer service. How can I help you today?";
        }
        
        // Check if user wants to exit
        if (containsAnyKeyword(lowercaseInput, exitPhrases)) {
            return "Thank you for chatting with us. Have a great day!";
        }
        
        // Handle specific common cases
        if (lowercaseInput.find("return") != string::npos) {
            return responses["return"];
        }
        
        if (lowercaseInput.find("shipping") != string::npos || 
            (lowercaseInput.find("ship") != string::npos && lowercaseInput.find("cost") != string::npos)) {
            return responses["shipping"];
        }
        
        // Process the query and find the best response
        return findBestResponse(input);
    }
    
    // Check if user wants to exit
    bool isExitRequest(const string& input) {
        return containsAnyKeyword(toLowerCase(input), exitPhrases);
    }
};

// For demo purposes - print helpful debug info
void printDebugKeywords(const string& input) {
    cout << "DEBUG: Input keywords detected: ";
    if (input.find("book") != string::npos) cout << "book ";
    if (input.find("ship") != string::npos) cout << "ship ";
    if (input.find("hour") != string::npos) cout << "hour ";
    if (input.find("return") != string::npos) cout << "return ";
    if (input.find("price") != string::npos) cout << "price ";
    if (input.find("order") != string::npos) cout << "order ";
    cout << endl;
}

int main() {
    Chatbot bot;
    string userInput;
    bool debugMode = false;  // Set to true to see debug information
    
    cout << "===== BookStore Customer Service Bot =====\n";
    cout << "Bot: Hello! Welcome to BookStore. How can I help you today?\n";
    cout << "(Type 'bye' to exit)\n";
    
    // Main conversation loop
    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);
        
        // Check if input is empty
        if (userInput.empty()) {
            cout << "Bot: I didn't catch that. Could you please type your question?\n";
            continue;
        }
        
        // Print debug info if enabled
        if (debugMode) {
            printDebugKeywords(userInput);
        }
        
        // Get response from the chatbot
        string response = bot.getResponse(userInput);
        cout << "Bot: " << response << endl;
        
        // Check if user wants to exit
        if (bot.isExitRequest(userInput)) {
            break;
        }
    }
    
    return 0;
}