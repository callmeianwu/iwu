#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <unordered_map>

using namespace std;

// This map holds all the variables and such 
unordered_map<string, double> variables;

// This is supposed to split a string into tokens based on a delimiter
vector<string> split(const string& str, char delimiter) 
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) 
    {
        tokens.push_back(token);
    }
    return tokens;
}

// This evaluates a mathematical expression in the discrete professor's favorite flavor - Reverse Polish Notation
double evaluateExpression(const vector<string>& tokens) 
{
    stack<double> numbers;
    for (const string& token : tokens) 
    {
        if (isdigit(token[0])) 
	{
            numbers.push(stod(token));
        } 
	else if (isalpha(token[0])) 
	{
            numbers.push(variables[token]);
        } 
	else 
	{
            double operand2 = numbers.top();
            numbers.pop();
            double operand1 = numbers.top();
            numbers.pop();

            if (token == "+") 
	    {
                numbers.push(operand1 + operand2);
            } 
	    else if (token == "-") 
	    {
                numbers.push(operand1 - operand2);
            } 
	    else if (token == "*") 
	    {
                numbers.push(operand1 * operand2);
            } 
	    else if (token == "/") 
	    {
                numbers.push(operand1 / operand2);
            }
        }
    }

    return numbers.top();
}

// This will calculate the sum of all the elements in a vector
double sum(const vector<double>& values) 
{
    return accumulate(values.begin(), values.end(), 0.0);
}

// This will find the max element in a vector
double max(const vector<double>& values) 
{
    return *max_element(values.begin(), values.end());
}

// This will find the min element in a vector
double min(const vector<double>& values) 
{
    return *min_element(values.begin(), values.end());
}

bool handleIfStatement(const vector<string>& tokens) {
    string conditionExpr = tokens[1];
    vector<string> conditionTokens = split(conditionExpr, '=');
    string varName = conditionTokens[0];
    double value = stod(conditionTokens[1]);
    if (variables[varName] == value) {
        vector<string> ifBlockTokens(tokens.begin() + 3, tokens.end());
        double result = evaluateExpression(ifBlockTokens);
        cout << "Condition met: " << " = " << result << endl;
	return true;
    }
    return false;
}

// I think everyone knows what this does
int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    // This will open the input file
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file.\n";
        return 1;
    }

    // Read the lines and split them up to get them to do what they need to do
    string line; 
    while (getline(inputFile, line)) 
    {
        vector<string> tokens = split(line, ' ');
        // Check if the line is a variable declaration (Should fully work now...)
	string thisVar = "";
	
	// Allowing the user to print out : Right now it is just "pr" for printing out result and "pl" for entire line
	bool print = false;
 	for (auto it = tokens.begin(); it != tokens.end(); ) 
	{
		if (*it == "pr") 
		{
            		print = true;
			it = tokens.erase(it);
			line.erase(line.find("pr"), 3);
        	}
		else if (*it == "pl") 
		{
			 it = tokens.erase(it); // Erase "pl" from tokens
                        line.erase(line.find("pl"), 3);
                        cout << line;
        	} 
		else 
		{
            		++it;
        	}
    	}

	// Variable Checking
	if (tokens[0] == "i") // Establish "integer" variable
	{
		// NOTE: NEED TO MAKE SURE USER CANNOT USE "i", "p", "sum", yada yada..., as variable names

		// Realized it would be easier for readability to allow it to fall through no matter what (for purpose of setting variable equal to equation)
		double value = 0;
            	
		thisVar = tokens[1];
		variables[tokens[1]] = value;
		//cout << "Variable declared: " << tokens[1] << " = " << value << endl;
		
		tokens.erase(tokens.begin(), tokens.begin() + 3);
        }
	else if (variables.count(tokens[0]) && tokens[1] == "=") // This is going to check if the variable has already been declared 
	{
		thisVar = tokens[0];
		//cout << "Variable found: " << thisVar << endl;
		tokens.erase(tokens.begin(), tokens.begin() + 2); // Remove the variable name and the equals sign
	}
	else // I have this for ignoring comments, but want to make sure user doesn't have to put space between comment and "//"
	{
		bool comment = false;
		for (const string& token : tokens)
		{
		    int cmtPos = token.find("//");
	            if (cmtPos == 0)
		    {
			comment = true;
			break;
		    }
		}

		if (comment)
		{
			continue;
		}
	}


        // This will evaluate everything in the rest of the line
        double result;
	if (tokens[0] == "if")
	{
		if (!handleIfStatement(tokens))
		{
			continue;
		}
	}
        if (tokens[0] == "sum") 
	{
            tokens.erase(tokens.begin()); // Remove the "sum" command
            vector<double> values;
            for (const string& token : tokens) 
	    {
                if (isdigit(token[0])) 
		{
                    values.push_back(stod(token));
                } 
		else if (isalpha(token[0])) 
		{
                    values.push_back(variables[token]);
                }
            }
            result = sum(values);
        } 
	else if (tokens[0] == "max") 
	{
            tokens.erase(tokens.begin()); // Remove the "max" command
            vector<double> values;
            for (const string& token : tokens) 
	    {
                if (isdigit(token[0])) 
		{
                    values.push_back(stod(token));
                } 
		else if (isalpha(token[0])) 
		{
                    values.push_back(variables[token]);
                }
            }
            result = max(values);
        } 
	else if (tokens[0] == "min") 
	{
            tokens.erase(tokens.begin()); // Remove the "min" command
            vector<double> values;
            for (const string& token : tokens) 
	    {
                if (isdigit(token[0])) 
		{
                    values.push_back(stod(token));
                } 
		else if (isalpha(token[0])) 
		{
                    values.push_back(variables[token]);
                }
            }
            result = min(values);
        } 

	else 
	{
            result = evaluateExpression(tokens);
        }
	
	// Changes the value of a variable if need-be
	if (thisVar != "")
	{
		variables[thisVar] = result;
		//cout << "Variable changed: " << thisVar << " = " << result << endl;
	}

	if (print) // This will print out result
	{
		cout << " -> " << result << endl;
		continue;	
	}
        // Output the result
        //cout << line << " = " << result << endl;
	//cout << result << endl; // Doing this instead because if the user does not want to print, they do not have to.
    }

    // Close the input file
    inputFile.close();

    return 0;
}

