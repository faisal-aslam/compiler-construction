
/*
* 
* This code is not for execution but understanding loop optimizations
*
*/

//****************  LOOP UNROLLING
//Original code
for (int i=0; i<n; i++) {
	arr[i] *= 2;
}

//Code after loop unrolling.
int i;
for (int i=0; i+1 < n; i=+2) {
	arr[i] *= 2;
	arr[i+1] *= 2;
}

if (i < n) { // handle remaining element when n is odd
	arr[i] *= 2;
}


//******************** LOOP INVARIANT

//original code
for (int i=0; i<n; i++) {
	arr[i] += x*y;
}

//code after loop invariant code motion.
int constant = x*y;
for (int i=0; i<n;i++) {
	arr[i] += constant;
}


//****************** LOOP FUSION

//original code.
for (int i=0; i<n; i+=2) {
	arr[i] += 1; //for odd indices
}
for (int i=1; i<n; i+=2) {
	arr[i] *=2; //for even indices
}

//After loop fusion.
for (int i=0;  i+1 < n; i+=2) {
	arr[i] *= 2; // even
	arr[i+1] += 1; //odd
}

// handle remaining odd index if n is odd.
if (n%2 != 0) {
	arr[n-1] += 1;
}

//****************  LOOP FISSION 

//original code.
for (int i=0; i<n; i++) {
	arr1[i] +=1;
	arr2[i] *=2; //different data sets.
}


//After loop fission
for (int i=0; i<n; i++) {
	arr1[i] +=1;
}

for (int i=0; i<n; i++) {
	arr2[i] += 2;
}


//********************* LOOP UNSWITCHING

for (int i=0; i<n; i++) {
	if (flag) {
		arr[i] += 1;
	} else {
		arr[i] *=2;
	}
}

//After loop unswitching.

if (flag) {
	for (int i=0; i<n; i++) {
		arr[i] +=1;
	}
} else {
	for (int i=0; i<n; i++) {
		arr[i] *= 2;
	}
}


































































