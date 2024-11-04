package service;

import core.Notification;
import service.interfaces.INotificationService;

/**
 * Implementation of the {@link INotificationService} interface.
 * This class follows SRP and OCP by allowing new notification types to be added easily.
 */
public class NotificationService implements INotificationService {

    /**
     * Sends a notification to the student based on the notification type.
     *
     * @param notification the notification to be sent
     * @throws UnsupportedOperationException if the notification type is not supported
     */
    @Override
    public void sendNotification(Notification notification) {
        switch (notification.getType()) {
            case EMAIL:
                sendEmail(notification);
                break;
            case SMS:
                sendSMS(notification);
                break;
            default:
                throw new UnsupportedOperationException("Notification type not supported");
        }
    }

    /**
     * Sends an email notification to the specified student.
     *
     * @param notification the notification containing the message and recipient details
     */
    private void sendEmail(Notification notification) {
        System.out.println("Sending Email to " + notification.getStudentId() + ": " + notification.getMessage());
    }

    /**
     * Sends an SMS notification to the specified student.
     *
     * @param notification the notification containing the message and recipient details
     */
    private void sendSMS(Notification notification) {
        System.out.println("Sending SMS to " + notification.getStudentId() + ": " + notification.getMessage());
    }
}
