#include <fstream>
#include <iomanip>
#include <iostream>

#include "dbscan.h"

#define MINIMUM_POINTS 4      // minimum number of cluster
#define EPSILON (0.75 * 0.75) // distance for clustering, metre^2

void readBenchmarkData(vector<Point>& points) {
	// load point cloud
	std::ifstream file;
	file.open("benchmark_hepta.dat", std::ifstream::in | std::ifstream::app);

	unsigned int minpts, num_points, cluster, i = 0;
	double epsilon;
	file >> num_points >> std::ws;

	Point* p = (Point*)calloc(num_points, sizeof(Point));

	while (i < num_points) {
		file >> p[i].x;
		file.ignore(1, ',');
		file >> p[i].y;
		file.ignore(1, ',');
		file >> p[i].z;
		file.ignore(1, ',');
		file >> cluster >> std::ws;
		p[i].clusterID = UNCLASSIFIED;
		points.push_back(p[i]);
		++i;
	}

	free(p);
	file.close();
}

void printResults(vector<Point>& points, int num_points) {
	int i = 0;
	printf("Number of points: %u\n"
		" x     y     z     cluster_id\n"
		"-----------------------------\n",
		num_points);
	std::cout << std::fixed << std::setprecision(2);
	while (i < num_points) {
		std::cout << std::setw(5) << points[i].x << ' ' << std::setw(5) << points[i].y << ' ' << std::setw(5) << points[i].z << ": " << points[i].clusterID << '\n';
		++i;
	}
}

int main() {
	vector<Point> points;

	// read point data
	readBenchmarkData(points);

	// constructor
	DBSCAN ds(MINIMUM_POINTS, EPSILON, points);

	// main loop
	ds.run();

	// result of DBSCAN algorithm
	printResults(ds.m_points, ds.getTotalPointSize());

	return 0;
}
