#include <stdio.h>
#include <math.h>

void readInFloat(float *target, char *label);
float bmi(float heightInMeters, float weightInKiloGrams);
const char* bmiInWords(float bmi);
float weightByBmiAndHeight(float bmi, float heightInMeters);
float heightByBmiAndWeight(float bmi, float weightInKiloGrams);

int main(int argc, char * argv[]) {
	float heightInMeters = 0;
	float weightInKiloGrams = 0;
	readInFloat(&heightInMeters, "deine Körpergröße in m");
	readInFloat(&weightInKiloGrams, "dein Körpergewicht in kg");

	printf("\n\n=====================================\n");
	printf("Du wiegst %.1fkg bei %.2fm\n", weightInKiloGrams, heightInMeters);

	float bmiValue = bmi(heightInMeters, weightInKiloGrams);
	printf("Dein BMI beträgt: %.1f\n", bmiValue);
	printf("Du hast %s\n\n", bmiInWords(bmiValue));
	printf(
		"Zwischen %.1fkg und %.1fkg wärst Du leicht untergewichtig.\n",
		weightByBmiAndHeight(17., heightInMeters),
		weightByBmiAndHeight(28.5, heightInMeters)
	);
	printf(
		"Dein Normalgewicht liegt zwischen %.1fkg und %.1fkg.\n",
		weightByBmiAndHeight(18.5, heightInMeters),
		weightByBmiAndHeight(25, heightInMeters)
	);
	printf(
		"Zwischen %.1fkg und %.1fkg wärst Du leicht übergewichtig.\n",
		weightByBmiAndHeight(25, heightInMeters),
		weightByBmiAndHeight(30, heightInMeters)
	);

	if(bmiValue > 25.) {
		printf(
			"Du müsstest %.2fm groß sein bei deinem Gewicht!\n",
			heightByBmiAndWeight(25, weightInKiloGrams)
		);
	} else if(bmiValue < 18.5) {
		printf(
			"Du müsstest %.2fm groß sein bei deinem Gewicht!\n",
			heightByBmiAndWeight(18.5, weightInKiloGrams)
		);
	}
}

void readInFloat(float *target, char *label) {
	printf("Gib bitte %s an:\n", label);
	scanf(" %f", target);
}

float bmi(float heightInMeters, float weightInKiloGrams) {
	return weightInKiloGrams / (heightInMeters * heightInMeters);
}

const char* bmiInWords(float bmi) {
	if(bmi < 16.) {
		return "starkes Untergewicht";
	} else if (bmi < 17.) {
		return "mäßiges Untergewicht";
	} else if (bmi < 18.5) {
		return "mäßiges Untergewicht";
	} else if (bmi < 25) {
		return "Normalgewicht";
	} else if (bmi < 30) {
		return "Übergewicht";
	} else if (bmi < 35) {
		return "Adipositas Grad I";
	} else if (bmi < 40) {
		return "Adipositas Grad II";
	} else {
		return "Adipositas Grad III";
	}
}

float weightByBmiAndHeight(float bmi, float heightInMeters) {
	return heightInMeters * heightInMeters * bmi;
}

float heightByBmiAndWeight(float bmi, float weightInKiloGrams) {
	return sqrt(weightInKiloGrams / bmi);
}
