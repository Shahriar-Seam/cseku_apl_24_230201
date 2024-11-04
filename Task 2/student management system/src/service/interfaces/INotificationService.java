package service.interfaces;

import core.Notification;

/**
 * Interface for notification services.
 * Follows the Interface Segregation Principle (ISP).
 */
public interface INotificationService {
    /**
     * Sends a notification to the student.
     *
     * @param notification the notification to be sent
     */
    void sendNotification(Notification notification);
}
