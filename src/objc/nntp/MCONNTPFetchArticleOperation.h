//
//  MCONNTPFetchArticleOperation.h
//  mailcore2
//
//  Created by Robert Widmann on 8/13/14.
//  Copyright (c) 2014 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCONNTPFETCHARTICLEOPERATION_H

#define MAILCORE_MCONNTPFETCHARTICLEOPERATION_H

#import <Foundation/Foundation.h>
#import <MailCore/MCONNTPOperation.h>

/** Fetch a message from NNTP3 */

typedef void (^MCONNTPOperationProgressBlock)(unsigned int current, unsigned int maximum);

@interface MCONNTPFetchArticleOperation : MCONNTPOperation

/** This block will be called as data is downloaded from the network */
@property (nonatomic, copy) MCONNTPOperationProgressBlock progress;

/** 
 Starts the asynchronous fetch operation.
 
 @param completionBlock Called when the operation is finished.
 
 - On success `error` will be nil and `data` will contain the message data
 
 - On failure, `error` will be set with `MCOErrorDomain` as domain and an 
 error code available in MCOConstants.h, `data` will be nil
 */
- (void) start:(void (^)(NSError * error, NSData * messageData))completionBlock;

@end

#endif
