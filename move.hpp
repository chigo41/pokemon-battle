#ifndef MOVE_HPP
#define MOVE_HPP

#include <string>

class Move {
	private:
    		std::string name;
    		std::string type;
    		int baseDamage;
    		int remainingUses;

	public:
    		
		/**
     * Function: Move
     * Description: Default constructor for the Move class.
     * Parameters: None
     * Returns: None
     * Side effects: Initializes member variables to default values.
     */
		Move();
    
		 /**
     * Function: Move
     * Description: Parameterized constructor for the Move class.
     * Parameters: name, type, baseDamage, remainingUses
     * Returns: None
     * Side effects: Initializes move attributes with given values.
     */
		Move(const std::string& name, const std::string& type, int baseDamage, int remainingUses);

		/**
     * Function: useMove
     * Description: Reduces the remaining uses of the move by 1.
     * Parameters: None
     * Returns: None
     * Side effects: Decreases remainingUses by 1.
     */
    		void useMove();

	/**
     * Function: hasUses
     * Description: Checks if the move has remaining uses.
     * Parameters: None
     * Returns: true if remainingUses > 0, false otherwise.
     * Side effects: None
     */
    		bool hasUses() const;
	/**
     * Function: getName
     * Description: Retrieves the name of the move.
     * Parameters: None
     * Returns: The move name as a string.
     * Side effects: None
     */
    		std::string getName() const;
    
/**
     * Function: getType
     * Description: Retrieves the type of the move.
     * Parameters: None
     * Returns: The move type as a string.
     * Side effects: None
     */
		std::string getType() const;
    
/**
     * Function: getBaseDamage
     * Description: Retrieves the base damage of the move.
     * Parameters: None
     * Returns: The base damage as an integer.
     * Side effects: None
     */
		int getBaseDamage() const;
    
 /**
     * Function: getRemainingUses
     * Description: Retrieves the remaining uses of the move.
     * Parameters: None
     * Returns: The remaining uses as an integer.
     * Side effects: None
     */
		int getRemainingUses() const;
};

#endif // MOVE_HPP

