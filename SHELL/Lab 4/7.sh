# Script for calculating the area of a circle

PI=3.14

echo Enter radius of the circle: 
read radius

area=$(echo "scale=2; $PI * $radius * $radius" | bc)

echo Area of circle with radius $radius = $area
