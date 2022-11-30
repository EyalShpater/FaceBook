#ifndef __MEMBERARRAY_H
#define __MEMBERARRAY_H

class Member;

class MemberArray
{
// add NOT_FOUND as static const
	Member** friends;
	int logSize;
	int physSize;

public:
	MemberArray();
	~MemberArray();

	int getLogSize() const { return logSize; }
	int getPhysSize() const { return physSize; }
	Member& getMemberByIndex(int index) { return *(friends[index]); }
	const Member& getMemberByIndex(int index) const { return *(friends[index]); }

	void push(Member& newMember);
	void pop(Member& other);
	int findMemberByName(const char* name) const;
	void showAllMembers() const;
	
private:
	MemberArray(const MemberArray&);

	void reserve();
	void myRealloc(int newSize);
};

#endif //__MEMBERARRAY_H