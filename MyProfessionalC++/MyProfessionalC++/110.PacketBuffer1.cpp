#include <iostream>
#include <queue>

using namespace std;

template <typename T> class PacketBuffer {
public:
	PacketBuffer(size_t maxSize = 0);

	// store a packet in the buffer
	bool bufferPacket(const T& packet);
	// get a packet
	T getPacket();
private:
	queue<T> mPackets;
	size_t mMaxSize;
};

template <typename T> PacketBuffer<T>::PacketBuffer(size_t maxSize) : mMaxSize(maxSize) {

}

template <typename T> bool PacketBuffer<T>::bufferPacket(const T& packet) {

	if (mMaxSize > 0 && mPackets.size() == mMaxSize) {
		// No more space. Drop the packet
		return false;
	}
	mPackets.push(packet);
	return true;
}

template <typename T> T PacketBuffer<T>::getPacket() {

	if (mPackets.empty()) {
		throw out_of_range("Buffer is empty");
	}

	T temp = mPackets.front();
	mPackets.pop();  // queue::pop() does not have return type
	return temp;
}

class IPPacket {
public:
	IPPacket(int id) : mID(id) {}
	int getID() const { return mID; }
private:
	int mID;
};

int main() {
	char c;
	PacketBuffer<IPPacket> ipPacket(3);

	// Add 4 packet
	for (int i = 1; i <= 4; ++i) {
		if (!ipPacket.bufferPacket(IPPacket(i))) {
			cout << "Pakcet" << i << " dropped (queue is full)." << endl;
		}
	}

	while (true) {
		try {
			IPPacket packet = ipPacket.getPacket();
			cout << "Processing packet " << packet.getID() << endl;
		}
		catch (const out_of_range&) {
			cout << "Queue is empty." << endl;
			break;
		}
	}

	cin >> c;
	return 0;
}

