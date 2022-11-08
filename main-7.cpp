
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"

using namespace std;
struct QuickFormat {
  string code;
  float distance;
};
// FIX *************
void quickSort(QuickFormat *s[], int low, int high);
int partition(QuickFormat *s[], int low, int high);
void simpleSortTotal(QuickFormat *a[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    NODE * head = new NODE;
    slist airports(head);			// Replace array with Linked List
    int   airportCount;
    QuickFormat a[13500];
    string tempstr;
    AIRPORT tempair;
    infile.open ("USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    { /* DO NOT TOUCH FILE READ IN */
        int   c=0;
        while (infile.good())
        {
            //cout << c;
            infile.getline(tempair.code, 256, ',');
            //cout << "code: "<<tempair.code << "\n";
            infile.getline(cNum, 256, ',');
            tempair.longitude = atof(cNum);
            //cout <<"long: " << tempair.longitude << "\n";
            infile.getline(cNum, 256, '\n');
            tempair.latitude = atof(cNum);
            //cout <<"lat: " << tempair.latitude << "\n";
            if (c ==0) {
              NODE first;
              first.value = tempair;
              NODE * header = &first;
              slist airports(header);
              //cout << "slist made\n";
            } else {
              //cout << "try to add \n";
              airports.add(tempair);
              a[c].code = tempair.code;
              a[c].distance = distanceEarth(tempair.latitude, tempair.longitude, 30.1944,97.67); 
              //cout << a[c].code << " "<< a[c].distance <<"\n";
              //cout << "added\n";
            }
            //if (!(c % 1000))
                //cout << tempair.code << " long: " << tempair.longitude << " lat: " << tempair.latitude <<  endl;

            
            
            //i++ ;
            c++;
          //cout << "done w/ c\n";
        }
        airportCount = c-1;
        infile.close();
        
         /*for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }*/



    }
    else
    {
        cout << "Error opening file";
    }

  //string print1 = airports.toString();
  //cout << print1;
  QuickFormat *distances[13410];
  for (int i = 1; i < 13410; i++) {
    distances[i] = &a[i];
    cout << i << " "<< distances[i]->code <<" "<< distances[i]->distance << "\n";
  }
  //cout << "finish transfer";
  //quickSort(distances, 1, 13411);
  simpleSortTotal(distances, 13409);
  cout << "tried quicksort";
  for (int i = 1; i < 101; i++) {
    cout << distances[i]->code << " " << distances[i]->distance << "\n";
  }
  cout << distances[13409]->code << " " << distances[13409]->distance << "\n";


  return 0;
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0


// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/
int partition(QuickFormat *s[], int low, int high) {
  QuickFormat piviot = *s[high];
  int i = low-1;
  for (int j = low; j <= high-1; j++) {
    //if current element is smaller than piviot **********
    if (s[j]->distance < piviot.distance) {
      i++;
      //s.swap(i, j); ********
      QuickFormat *temp = s[i];
      s[i] = s[j];
      s[j] = temp;
    }
  }

  //s.swap(i+1, high); ******
  QuickFormat *temp = s[i+1];
  s[i+1] = s[high];
  s[high] = temp;
  return i+1;
}
void quickSort(QuickFormat *s[], int low, int high) {
  if (low < high) {
    int pindex = partition(s, low, high);
    quickSort(s, low, pi-1);
    quickSort(s, pi+1, high);
  }
}
void simpleSortTotal(QuickFormat *a[], int c)
{
	
	for (int i=1; i < c; i++)
		for (int j=i; j < c; j++)
		if ((*a[i]).distance > (*a[j]).distance)
		{
      QuickFormat *temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      
		}
} 