#include <iostream>
using namespace std;

struct Tshirt{
    long int priceTshirt;
    int frontcolor;
    int backcolor;
};

void merge(Tshirt arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Tshirt* L = new Tshirt[n1];
    Tshirt* R = new Tshirt[n2];
    for (int i = 0; i < n1; i++) {
        L[i].priceTshirt = arr[left + i].priceTshirt;
        L[i].frontcolor = arr[left + i].frontcolor;
        L[i].backcolor = arr[left + i].backcolor;
    }

    for (int j = 0; j < n2; j++) {
        R[j].priceTshirt = arr[mid + 1 + j].priceTshirt;
        R[j].frontcolor = arr[mid + 1 + j].frontcolor;
        R[j].backcolor = arr[mid + 1 + j].backcolor;
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].priceTshirt <= R[j].priceTshirt) {
            arr[k] = L[i];
            i++;
            k++;
        }
        else {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(Tshirt arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    // Seller inputs
    int numTshirt; cin >> numTshirt; // Input the number of T-shirts

    Tshirt* tshirt = new Tshirt[numTshirt];

    // Input the prices
    for (int i = 0; i < numTshirt; i++) {
        cin >> tshirt[i].priceTshirt;
    }

    // Input the front color
    for (int i = 0; i < numTshirt; i++) {
        cin >> tshirt[i].frontcolor;
    }

    // Input for the back color
    for (int i = 0; i < numTshirt; i++) {
        cin >> tshirt[i].backcolor;
    }

    mergeSort(tshirt, 0, numTshirt - 1);

    // -----------------------------------

    // Buyer inputs
    int numBuyers; cin >> numBuyers;
    int* favcolor = new int[numBuyers];

    // Input the buyers' favorite colors
    for (int i = 0; i < numBuyers; i++) {
        cin >> favcolor[i];
    }

    // -----------------------------------

    // Use loop runs parallel -> Find the fav color in n T-shirts
    // - Found -> Find out the cheapest one with the fav color -> Print the price
    // - Not found -> print -1

    int ptr[4] = {0, 0, 0, 0};

    for (int i = 0; i < numBuyers; i++) {
        int fav = favcolor[i];
        int ans = -1;

        // Move the specific pointer for the favorite color
        while (ptr[fav] < numTshirt) {
            int idx = ptr[fav];

            // If it's already sold, skip it forever for THIS color
            if (tshirt[idx].priceTshirt == 0) {
                ptr[fav]++;
                continue;
            }

            // Check for color match
            if (tshirt[idx].frontcolor == fav || tshirt[idx].backcolor == fav) {
                ans = tshirt[idx].priceTshirt;
                tshirt[idx].priceTshirt = 0; // Mark as sold
                // Don't increment ptr[fav] yet, just break
                break;
            }

            // Not a match? Move the pointer past it.
            ptr[fav]++;
        }
        cout << ans << " ";
    }

    // delete[] priceTshirt;
    // delete[] frontcolor;
    // delete[] backcolor;
    delete[] tshirt;
    delete[] favcolor;

    return 0;
}