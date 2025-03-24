Smart Waste Management System - Documentation
Introduction
The Smart Waste Management System is designed to help with collecting waste through monitoring waste bin fill levels and assigning collection trucks. It addresses the need in many urban areas, where waste collection is inefficient because of irregular schedules and overfilled bins. This system provides a solution by tracking bin levels and allocating collection resources, to reduce unnecessary trips and improve city cleanliness.

Features and Functionality
Waste Bin Management - This tracks the waste bins that are recyclable and the non-recyclable ones using inheritance. It also checks the locations of the bins and the levels they are filled. 
Allocating Trucks- The dynamic memory is used to store the bins and manage them. the trucks are assigned waste bins based on how full they are.
Exception Handling- this prevents impossible fill levels as they must be between 0-100%. The input from the user has to be between these values.

Code Structure
Classes
-	WasteBin (Base Class) it stores location and fill level.
-	RecyclableBin and NonRecyclableBin (Derived Classes) it inherits from WasteBin.
-	Truck. It stores a list of assigned bins.

Sample Execution
User Input:
Enter fill level (0-100): 45
Enter fill level (0-100): 85

Program Output:
Truck T123 assigned bins:
[Recyclable] Location: Downtown | Fill Level: 45%
[Non-Recyclable] Location: Suburb | Fill Level: 85%
