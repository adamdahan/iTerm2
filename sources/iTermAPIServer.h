//
//  iTermAPIServer.h
//  iTerm2
//
//  Created by George Nachman on 11/3/16.
//
//

#import <Foundation/Foundation.h>
#import "Api.pbobjc.h"

@protocol iTermAPIServerDelegate<NSObject>
- (BOOL)apiServerAuthorizeProcess:(pid_t)pid;
- (void)apiServerGetBuffer:(ITMGetBufferRequest *)request handler:(void (^)(ITMGetBufferResponse *))handler;
- (void)apiServerGetPrompt:(ITMGetPromptRequest *)request handler:(void (^)(ITMGetPromptResponse *))handler;
- (void)apiServerNotification:(ITMNotificationRequest *)request
                   connection:(id)connection
                      handler:(void (^)(ITMNotificationResponse *))handler;
- (void)apiServerRemoveSubscriptionsForConnection:(id)connection;
@end

@interface iTermAPIServer : NSObject

@property (nonatomic, weak) id<iTermAPIServerDelegate> delegate;

- (void)postAPINotification:(ITMNotification *)notification toConnection:(id)connection;

@end