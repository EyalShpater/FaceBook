#ifndef __MEMBERARRAY_H
#define __MEMBERARRAY_H

class Member;

class MemberArray
{
public:
	static const int DEFAULT_PHYS_SIZE = 2; // make all of this static in the h file
	static const int DEFAULT_LOG_SIZE = 0;
	static const int NOT_FOUND = -1;
	static const int EQUAL = 0;

private:
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