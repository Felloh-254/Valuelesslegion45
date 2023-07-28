//Using the array<T, N> to create the BMI table
//BMI  = weight/(heigth*height)
//Weight in kilograms and height is in metres

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

int main(int argc, char const *argv[])
{
	//Weight details
	const unsigned max_weight{250};//The maximum weight in pounds(lbs)
	const unsigned min_weight{100};//Minimum weight in pounds(lbs)
	const unsigned weight_step{10};//Value to be added to the current weight to get the next weight
	const unsigned weight_count{1 + (max_weight - min_weight)/ weight_step};//The size of the weight array

	//Height details
	const unsigned max_height{84};//The maximum height in inches
	const unsigned min_height{48};//Minimum height in inches
	const unsigned height_step{2};//Value to be added to the current height to get the next height
	const unsigned height_count{1 + (max_height - min_height)/ height_step};//The size of the height array

	//Some constant details
	const double pounds_per_kg{2.2};//equivalent to 1kg i.e pound per kilogram
	const double inch_per_metre{39.37};//equivalent to 1metre i.e inch per metre
	array<unsigned, weight_count>weight_lbs{};
	array<unsigned, height_count>height_inch{};

	//Filling the weights in steps of 10 as defined above starting from 100
	for(size_t i{}, weight{min_weight}; i<weight_count; weight+=weight_step, ++i){
		weight_lbs[i]=weight;
	}

	//Filling the heigts in steps of 2 as defined above starting from 48
	for(size_t i{}, height{min_height}; i<height_count; height+=height_step, ++i){
		height_inch.at(i)=height;
	}

	//Printing the heading
	cout<<setw(7)<<"He|We |";
	for(auto weight : weight_lbs){
		cout<<setw(5)<<weight<<" |";
	}
	cout<<endl;

	//Printing the line below the heading
	for(size_t i{1}; i<weight_count; ++i){
		cout<<"--------";
	}
	cout<<endl;

	double bmi{};//For storing the BMI
	unsigned int feet{};//The whole feet for the output
	unsigned int inches{};//The whole inch for the output
	const unsigned int inch_per_foot{12};

	for(auto h : height_inch){
		feet=h/inch_per_foot;
		inches=h%inch_per_foot;

		cout<<setw(2) << feet <<"'"<<setw(2)<<inches<<'"'<<'|';
		cout<<fixed<<setprecision(1);

		for(auto w : weight_lbs){
			auto height_metres = h/inch_per_metre;
			auto weight_metres = w/pounds_per_kg;
			bmi = weight_metres/(height_metres*height_metres);
			cout<<setw(1)<< ""<<bmi<<" |";
		}
	    cout<<endl;
	}
	for(size_t i{1}; i<weight_count; ++i){
		cout<<"--------";
	}
	cout<<endl;
}









