/*
 * TreeNode.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

