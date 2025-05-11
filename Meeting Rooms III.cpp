class Solution {
    public:
        int mostBooked(int n, vector<vector<int>> &meetings) {
            sort(meetings.begin(), meetings.end()); // Sort meetings by start time
            
            priority_queue<int, vector<int>, greater<int>> availableRooms; // Min-Heap for room numbers
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> ongoingMeetings; // Min-Heap (endTime, roomNumber)
            
            vector<int> meetingCount(n, 0); // Track meetings per room
            
            for (int i = 0; i < n; i++) {
                availableRooms.push(i); // Initialize all rooms as available
            }
            
            for (auto &meeting : meetings) {
                long long start = meeting[0], end = meeting[1];
    
                // Free rooms where meetings have ended
                while (!ongoingMeetings.empty() && ongoingMeetings.top().first <= start) {
                    availableRooms.push(ongoingMeetings.top().second); // Free up room
                    ongoingMeetings.pop();
                }
    
                if (!availableRooms.empty()) {
                    int room = availableRooms.top();
                    availableRooms.pop();
                    ongoingMeetings.push({end, room});
                    meetingCount[room]++;
                } else {
                    // Delay meeting until the earliest room is free
                    auto earliestMeeting = ongoingMeetings.top();
                    ongoingMeetings.pop();
                    int delayedRoom = earliestMeeting.second;
                    long long newEndTime = earliestMeeting.first + (end - start);
                    ongoingMeetings.push({newEndTime, delayedRoom});
                    meetingCount[delayedRoom]++;
                }
            }
    
            // Find room with max meetings
            int maxRoom = 0;
            for (int i = 1; i < n; i++) {
                if (meetingCount[i] > meetingCount[maxRoom]) {
                    maxRoom = i;
                }
            }
            
            return maxRoom;
        }
    };