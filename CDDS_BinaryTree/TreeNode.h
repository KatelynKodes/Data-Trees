#pragma once

template<typename T>
class TreeNode
{
public:
	TreeNode() {};
	TreeNode(T value);
	~TreeNode() {};

	/// <summary>
	/// Returns whether or not this node has a left child
	/// </summary>
	bool hasLeft();

	/// <summary>
	/// Returns whether or not this node has a right child
	/// </summary>
	bool hasRight();

	/// <summary>
	/// Returns the data this node contains 
	/// </summary>
	T getData() { return m_value; }

	/// <summary>
	/// Gets the child to the left of this node
	/// </summary>
	TreeNode<T>* getLeft() { return m_left; }

	/// <summary>
	/// Gets the child to the right of this node
	/// </summary>
	TreeNode<T>* getRight() { return m_right; }

	/// <summary>
	/// Sets the value of the data this node is storing to be the given value
	/// </summary>
	/// <param name="value">The value to change the data to</param>
	void setData(T value) { m_value = value; }

	/// <summary>
	/// Sets the left child of this node to be the given node
	/// </summary>
	/// <param name="node">The node to set as this nodes new child</param>
	void setLeft(TreeNode<T>* node) { m_left = node; }

	/// <summary>
	/// Sets the left child of this node to be the given node
	/// </summary>
	/// <param name="node">The node to set as this nodes new child</param>
	void setRight(TreeNode<T>* node) { m_right = node; }

	void draw(int x, int y, bool selected = false);

private:
	T m_value;

	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
};


template<typename T>
inline TreeNode<T>::TreeNode(T value)
{
	m_value = value;
}

template<typename T>
inline bool TreeNode<T>::hasLeft()
{
	if (m_left)
		return true;
	else
		return false;
}

template<typename T>
inline bool TreeNode<T>::hasRight()
{
	if (m_right)
		return true;
	else
		return false;
}

template<typename T>
inline void TreeNode<T>::draw(int x, int y, bool selected)
{
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	DrawCircle(x, y, 30, YELLOW);
	
	if (selected)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);

	DrawText(buffer, x - 12, y - 12, WHITE);

}
