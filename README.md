A guide to how I implemented the uml diagram:

Component 1:
Component: FarmUnit
Role: The FarmUnit class provides a unified interface for all farm-related entities, whether they are simple elements like CropField and Barn or composite structures like Farm.
Variables:
	• string name;
		○ Reason: Each FarmUnit should have a name or identifier to distinguish between different units, whether it's a CropField, Barn, or an entire Farm.
Functions:
	• virtual int getTotalCapacity() const = 0;
		○ Reason: This function must be implemented by all derived classes to return the total storage capacity. This is essential because both CropField and Barn need to provide their capacities, and Farm may aggregate the capacities of its child units.
	• virtual string getName() const = 0;
		○ Reason: This function returns the name of the farm unit, enabling identification and differentiation within the system.
	• virtual void add(FarmUnit* unit);
		○ Reason: As part of the composite structure, the FarmUnit interface should define the ability to add child units, which will be specifically implemented by the Farm class. CropField and Barn would provide empty implementations or throw exceptions since they do not contain children.
	• virtual void remove(FarmUnit* unit);
		○ Reason: Similar to the add method, this allows for the removal of child units, again implemented by Farm while the leaves (CropField and Barn) may not utilize it.
	• virtual vector<FarmUnit*> getChildren() const;
		○ Reason: To retrieve the list of children. The Farm class would return its components, while CropField and Barn might return an empty list.


Composite: Farm
Role: The Farm class aggregates multiple FarmUnit objects, managing them collectively.
Variables:
	• vector<FarmUnit*> units;
		○ Reason: This vector stores all the child components (CropField, Barn, or other FarmUnit objects) that belong to the Farm. It's essential for managing the composite structure.
Functions:
	• int getTotalCapacity() const override;
		○ Reason: This function should calculate and return the total capacity of the farm by summing the capacities of all its child units.
	• string getName() const override;
		○ Reason: Returns the name of the farm, useful for identifying the farm in the system.
	• void add(FarmUnit* unit) override;
		○ Reason: Implements the method to add a FarmUnit to the farm, thereby building the composite structure.
	• void remove(FarmUnit* unit) override;
		○ Reason: Implements the method to remove a FarmUnit from the farm, allowing dynamic changes to the structure.
	• vector<FarmUnit*> getChildren() const override;
		○ Reason: Returns the list of children, enabling traversal and other operations over the farm’s components.


Leaf: CropField
Role: The CropField class represents an individual crop field in the farm system.
Variables:
	• string cropType;
		○ Reason: Stores the type of crop being grown (e.g., wheat, corn). This is important for managing and differentiating fields based on the crops they produce.
	• int totalCapacity;
		○ Reason: Stores the maximum storage capacity of the crop field.
	• int currentStoredCrops;
		○ Reason: Tracks the current amount of stored crops in the field.
	• SoilState* soilState;
		○ Reason: Points to the current soil state (e.g., DrySoil, FruitfulSoil), which affects the yield and productivity of the field.
Functions:
	• int getTotalCapacity() const override;
		○ Reason: Returns the total storage capacity specific to the crop field.
	• string getName() const override;
		○ Reason: Returns the name or type of crop in the field, helping to identify the field in the farm system.
	• string getCropType() const;
		○ Reason: Specifically returns the type of crop in the field, which may influence other operations like fertilization or harvesting.
	• string getSoilStateName() const;
		○ Reason: Returns the name of the current soil state, which can be critical for determining the field's productivity and managing logistics.


Leaf: Barn
Role: The Barn class represents a storage unit within the farm.
Variables:
	• int totalCapacity;
		○ Reason: Stores the maximum capacity of the barn, which is crucial for managing how much produce or resources it can hold.
Functions:
	• int getTotalCapacity() const override;
		○ Reason: Returns the storage capacity specific to the barn.
	• string getName() const override;
		○ Reason: Returns the name or identifier of the barn, useful for tracking within the farm.


Reasoning Behind the Design
	• Uniform Interface (FarmUnit): By defining a common interface, you allow the system to treat both individual units (CropField, Barn) and composites (Farm) uniformly. This simplifies interactions and makes the system extensible.
	• Composite Operations (Farm): The composite class (Farm) can perform operations on its children, such as calculating total capacity or managing additions and removals of units.
	• Leaf Simplicity (CropField, Barn): The leaf classes implement the core functionality specific to their role in the system, such as tracking crop types or storage capacities, without the overhead of managing children.

Component 2:

1. SoilState (State)
	• Variables:
		○ None (states usually don't have internal data unless specific to a state's behavior).
	• Functions:
		○ virtual void harvestCrops(CropField* field) = 0;
			§ Reason: Defines how crops are harvested based on the current soil state.
		○ virtual void rain(CropField* field) = 0;
			§ Reason: Defines how the soil state changes when rain is applied.
		○ virtual std::string getName() const = 0;
			§ Reason: Returns the name of the soil state, which can be used for reporting or UI purposes.
2. DrySoil, FruitfulSoil, FloodedSoil (Concrete States)
	• Variables:
		○ None or minimal (specific to the state’s behavior if necessary).
	• Functions:
		○ void harvestCrops(CropField* field) override;
			§ Reason: Implements the specific behavior for harvesting in the dry state.
		○ void rain(CropField* field) override;
			§ Reason: Implements how the soil transitions from DrySoil to another state after rainfall.
		○ std::string getName() const override;
			§ Reason: Returns the name of the current state, e.g., "Dry", "Fruitful", "Flooded".
3. CropField (Context)
	• Variables:
		○ SoilState* currentState;
			§ Reason: Stores the current state of the soil. This pointer/reference is used to delegate operations to the appropriate state object.
	• Functions:
		○ void setState(SoilState* newState);
			§ Reason: Allows for changing the current soil state. This is typically called within state-specific methods (e.g., when rain transitions from DrySoil to FruitfulSoil).
		○ void harvestCrops();
			§ Reason: Delegates the harvesting operation to the current soil state.
		○ void rain();
			§ Reason: Delegates the rain operation to the current soil state.
		○ std::string getSoilStateName() const;
			§ Reason: Returns the name of the current soil state by calling getName() on the current state object.
Explanation of Roles and Interactions
	• Context (CropField): Holds a reference to a SoilState object, which determines its behavior for certain actions. The context can switch states dynamically based on events (like applying rain or harvesting crops).
	• State (SoilState): Provides a common interface that all concrete states must implement. This ensures that the CropField can interact with any state in a uniform way.
	• Concrete States (DrySoil, FruitfulSoil, FloodedSoil): Each concrete state encapsulates specific behavior relevant to that state. For example, DrySoil may yield minimal crops and transition to FruitfulSoil after rain, while FloodedSoil prevents any further growth.
	• Client: The client interacts with the CropField and triggers operations like harvestCrops() or rain(), without needing to know the specific state of the soil. The context and state handle the behavior internally, ensuring that the correct actions are taken based on the current state.

