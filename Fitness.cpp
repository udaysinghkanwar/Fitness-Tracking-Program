#include <algorithm>
#include <iostream>
#include <vector>

struct Exercise {
  std::string name;
  int duration; // in minutes
  double caloriesBurned;
};

// Function to calculate total calories burned
double calculateTotalCaloriesBurned(const std::vector<Exercise> &exercises) {
  double totalCalories = 0.0;
  for (const Exercise &exercise : exercises) {
    totalCalories += exercise.caloriesBurned;
  }
  return totalCalories;
}

// Function to display exercise log
void displayExerciseLog(const std::vector<Exercise> &exercises) {
  std::cout << "Exercise Log:" << std::endl;
  for (const Exercise &exercise : exercises) {
    std::cout << "Exercise: " << exercise.name
              << ", Duration: " << exercise.duration
              << " minutes, Calories Burned: " << exercise.caloriesBurned
              << std::endl;
  }
}

// Function to find the longest exercise duration
int findLongestExercise(const std::vector<Exercise> &exercises) {
  int longestDuration = 0;
  for (const Exercise &exercise : exercises) {
    if (exercise.duration > longestDuration) {
      longestDuration = exercise.duration;
    }
  }
  return longestDuration;
}

// Function to suggest an exercise based on the calories burned
std::string suggestExercise(double caloriesBurned) {
  if (caloriesBurned >= 500) {
    return "You burned a lot of calories! Try a high-intensity workout like "
           "HIIT.";
  } else if (caloriesBurned >= 250) {
    return "Great job! You burned a decent amount of calories. Consider going "
           "for a run.";
  } else if (caloriesBurned >= 100) {
    return "Good effort! Try some moderate exercises like cycling or swimming.";
  } else {
    return "Keep up the good work! Remember, every little bit counts.";
  }
}

// Function to filter exercises by minimum calories burned
std::vector<Exercise>
filterExercisesByCalories(const std::vector<Exercise> &exercises,
                          double minCalories) {
  std::vector<Exercise> filteredExercises;
  for (const Exercise &exercise : exercises) {
    if (exercise.caloriesBurned >= minCalories) {
      filteredExercises.push_back(exercise);
    }
  }
  return filteredExercises;
}

// Function to shuffle the exercise log randomly
void shuffleExerciseLog(std::vector<Exercise> &exercises) {
  std::random_shuffle(exercises.begin(), exercises.end());
}

// Function to calculate average calories burned per minute
double calculateAverageCaloriesBurnedPerMinute(
    const std::vector<Exercise> &exercises) {
  double totalCalories = calculateTotalCaloriesBurned(exercises);
  double totalDuration = 0.0;
  for (const Exercise &exercise : exercises) {
    totalDuration += exercise.duration;
  }
  if (totalDuration > 0.0) {
    return totalCalories / totalDuration;
  } else {
    return 0.0;
  }
}

// Function to display exercise statistics
void displayExerciseStatistics(const std::vector<Exercise> &exercises) {
  std::cout << "Exercise Statistics:" << std::endl;
  std::cout << "Total Exercises: " << exercises.size() << std::endl;
  std::cout << "Total Calories Burned: "
            << calculateTotalCaloriesBurned(exercises) << " calories"
            << std::endl;
  std::cout << "Average Calories Burned per Minute: "
            << calculateAverageCaloriesBurnedPerMinute(exercises)
            << " calories/min" << std::endl;
}

int main() {
  const int MAX_EXERCISES = 5;
  std::vector<Exercise> exerciseLog;

  // Prompt user for exercise details
  char choice;
  int exerciseCount = 0;
  do {
    Exercise exercise;
    std::cout << "Enter exercise details:" << std::endl;
    std::cout << "Exercise Name: ";
    std::cin.ignore(); // Ignore newline character
    std::getline(std::cin, exercise.name);
    std::cout << "Duration (in minutes): ";
    std::cin >> exercise.duration;
    std::cout << "Calories Burned: ";
    std::cin >> exercise.caloriesBurned;

    // Add exercise to the log if there is space available
    if (exerciseCount < MAX_EXERCISES) {
      exerciseLog.push_back(exercise);
      exerciseCount++;
    } else {
      std::cout << "Exercise log is full. Cannot add more exercises."
                << std::endl;
      break;
    }

    std::cout << "Do you want to enter another exercise? (Y/N): ";
    std::cin >> choice;
  } while (choice == 'Y' || choice == 'y');

  // Calculate total calories burned
  double totalCaloriesBurned = calculateTotalCaloriesBurned(exerciseLog);

  // Display exercise log
  std::cout << std::endl;
  displayExerciseLog(exerciseLog);

  // Display total calories burned
  std::cout << "Total Calories Burned: " << totalCaloriesBurned << " calories"
            << std::endl;

  // Find the longest exercise duration
  int longestExerciseDuration = findLongestExercise(exerciseLog);
  std::cout << "Longest Exercise Duration: " << longestExerciseDuration
            << " minutes" << std::endl;

  // Sort exercises by duration in descending order
  std::sort(exerciseLog.begin(), exerciseLog.end(),
            [](const Exercise &a, const Exercise &b) {
              return a.duration > b.duration;
            });

  // Display sorted exercise log
  std::cout << std::endl;
  std::cout << "Exercise Log (Sorted by Duration):" << std::endl;
  displayExerciseLog(exerciseLog);

  // Filter exercises by minimum calories burned
  double minCalories = 200.0;
  std::vector<Exercise> filteredExercises =
      filterExercisesByCalories(exerciseLog, minCalories);

  // Display filtered exercise log
  std::cout << std::endl;
  std::cout << "Exercise Log (Filtered by Minimum Calories " << minCalories
            << "):" << std::endl;
  displayExerciseLog(filteredExercises);

  // Shuffle the exercise log
  shuffleExerciseLog(exerciseLog);

  // Display shuffled exercise log
  std::cout << std::endl;
  std::cout << "Exercise Log (Shuffled):" << std::endl;
  displayExerciseLog(exerciseLog);

  // Display exercise statistics
  std::cout << std::endl;
  displayExerciseStatistics(exerciseLog);

  return 0;
}
