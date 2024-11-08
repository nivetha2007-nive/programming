
#include <iostream>
#include <string>
using namespace std;

// Class representing a quiz question
class Question {
public:
    string questionText;
    string options[4];
    char correctAnswer;

    // Constructor to initialize the question
    Question(string q, string a, string b, string c, string d, char correct) {
        questionText = q;
        options[0] = a;
        options[1] = b;
        options[2] = c;
        options[3] = d;
        correctAnswer = correct;
    }

    // Function to display the question
    void displayQuestion() {
        cout << questionText << endl;
        cout << "A. " << options[0] << endl;
        cout << "B. " << options[1] << endl;
        cout << "C. " << options[2] << endl;
        cout << "D. " << options[3] << endl;
    }

    // Function to check the answer
    bool checkAnswer(char answer) {
        return answer == correctAnswer;
    }
};

// Function to conduct a quiz session
int conductQuiz(Question questions[], int numQuestions) {
    int score = 0;
    char answer;

    for (int i = 0; i < numQuestions; ++i) {
        questions[i].displayQuestion();
        cout << "Enter your answer (A/B/C/D): ";
        cin >> answer;
        answer = toupper(answer);  // Convert to uppercase to handle lowercase input

        if (questions[i].checkAnswer(answer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer was " << questions[i].correctAnswer << "." << endl;
        }
        cout << endl;
    }
    return score;
}

int main() {
    // Medium level questions
    Question mediumQuestions[] = {
Question ("who developed C language?", "Dennis retchie", "james gosling", "brendan eich", "guido van rossum", 'A'),
Question ("Which function is used to find the length of a string?", "strlen()", "len()", "length", "len", 'C'),
Question ("what is file extension for a C?", "c", "cpp", "py", "html", 'A'),
Question ("what is the output of print("",2+4);?","8","5","6","error",'D'),
Question ("size of int datatype","5","6","2","4",'D'),
Question ("what key word to exit a loop?","do","continue","break","cut",'C'),
Question ("data type of a single character in C?","int","string","char","double",'C'),

    };

    // Hard level questions
    Question hardQuestions[] = {
        Question("Which of the following is not a keyword in C?", "auto","register","boolean","static",'C'),
        Question("Function of \\b in printf?", "newline", "tab", "backspace", "break", 'C'),
        Question("Meaning of NULL in C?", "nullpointer", "void", "0", "NULL", 'A'),
    };

    cout << "Welcome to the Medium Level Quiz!" << endl ;
    int mediumScore = conductQuiz(mediumQuestions, 7);

    // Display score for medium level
    cout << "Your total score in Medium Level is: " << mediumScore << " out of 7." << endl;

    // Check if user qualifies for hard level
    if (mediumScore >= 5) {  // Check if score is 5 or more
        cout << "Congratulations! You've qualified for the Hard Level!" << endl;
        cout << "Welcome to the Hard Level Quiz!" << endl;

        int hardScore = conductQuiz(hardQuestions, 3);

        // Display score for hard level
        cout << "Your total score in Hard Level is: " << hardScore << " out of 3." << endl;

        // Combine scores
        int totalScore = mediumScore + hardScore;
        cout << "Your overall score is: " << totalScore << " out of 10." << endl;

        // Feedback based on total score
        if (totalScore == 10) {
            cout << "Excellent! You got all questions right!" << endl;
        } else if (totalScore >= 9) {
            cout << "Great job! Almost perfect!" << endl;
        } else if (totalScore >= 7) {
            cout << "Good effort! Try to improve!" << endl;
        } else {
            cout << "Keep practicing!" << endl;
        }
    } else {
        cout << "Congratulations! You have completed the Medium Level!" << endl;
        cout << "Your score is too low to advance to the Hard Level. Keep practicing!" << endl;
    }

    return 0;
}


