#include <iostream>
#include <string>

// This will hold the input string.
string input;

// This keeps track of the position in the input string (lookahead).
int lookahead = 0;

// Function to handle syntax errors.
void error() {
	cout << "syntax error" << endl;
	exit(1);
}

// Function to match the expected character and move the lookahead.
void match(char expected) {
	// If the current character matches the expected one, consume it.
	if (lookahead < input.size() && input[lookahead] == expected) {
		lookahead++; // Advances to the next character in the input string.
	} else {
		error(); // If there's a mismatch, trigger a syntax error.
	}
}

/*
Grammar:
S → a A | b  
A → B A | C | ε
B → b
C → c
*/

// Declare all functions corresponding to non-terminals.
void S(); // Function for non-terminal S.
void A(); // Function for non-terminal A.
bool B(); // Function for non-terminal B.
bool C(); // Function for non-terminal C.

// Function for non-terminal S, which has two productions: a A or b.
void S() {
	// If the current symbol is 'a', we call A to handle the production 'a A'.
	if (input[lookahead] == 'a') {
		match('a');
		A();
	} 
	// If the current symbol is 'b', we consume it as part of the production 'b'.
	else if (input[lookahead] == 'b') {
		match('b');
	} 
	// If neither condition is met, it's a syntax error.
	else {
		error();
	}
}

// Function for non-terminal A, which has three possible productions: B A, C, or ε.
void A() {
	// If B returns true (matches 'b'), then we recursively call A (B A).
	if (B()) {
		A(); // Calls A again for the second production B A.
	} 
	// If C doesn't return true (i.e., it's not 'c'), we consider it the epsilon case.
	else if (!C()) {
		// Epsilon production, so we simply do nothing and return.
	}
}

// Function for non-terminal B, which matches the terminal 'b'.
bool B() {
	// If the current symbol is 'b', we consume it.
	if (input[lookahead] == 'b') {
		match('b');
		return true;
	}
	// If it's not 'b', return false.
	return false;
}

// Function for non-terminal C, which matches the terminal 'c'.
bool C() {
	// If the current symbol is 'c', we consume it.
	if (input[lookahead] == 'c') {
		match('c');
		return true;
	}
	// If it's not 'c', return false.
	return false;
}

int main() {
	// Prompt the user to enter the input string.
	cout << "Enter your input" << endl;
	cin >> input;
	
	// Append an end-of-input marker ($) to indicate the end of the string.
	input = input + '$';
	
	// Start parsing by calling the function for the start symbol S.
	S();
	
	// If the entire input has been parsed and the end marker is reached, the input is valid.
	if (input[lookahead] == '$') {
		cout << "Input is part of our language" << endl;
	} 
	// If there's more input after the end marker, trigger a syntax error.
	else {
		error();
	}
	return 0;
}

