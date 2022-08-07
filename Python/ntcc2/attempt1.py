dropout_amt = 0.1

model = Sequential()
# regularizer = regularizers.l1()
# regularizer = regularizers.l2()
regularizer = regularizers.l1_l2()

model.add(
    Dense(
        units=4624,
        input_shape=(4624,),
        # kernel_initializer="lecun_uniform",
        # kernel_initializer="glorot_uniform",
        kernel_initializer="he_uniform",
        kernel_regularizer=regularizer,
        # activation="relu"
        # activation="sigmoid",
        # activation="elu"
        # activation="selu"
        # activation="softmax"
        # activation="softplus"
        # activation="softsign",
    )
)
model.add(Activation("relu"))
model.add(BatchNormalization())
model.add(Dropout(dropout_amt))

model.add(Dense(units=512))
model.add(Activation("relu"))
model.add(BatchNormalization())
model.add(Dropout(dropout_amt))

model.add(Dense(units=512))
model.add(Activation("relu"))
model.add(BatchNormalization())
model.add(Dropout(dropout_amt))

model.add(Dense(units=512))
model.add(Activation("relu"))
model.add(BatchNormalization())
model.add(Dropout(dropout_amt))

model.add(Dense(units=512))
model.add(Activation("relu"))
model.add(BatchNormalization())
model.add(Dropout(dropout_amt))

# model.add(Dense(units=512, activation="selu"))
# model.add(Dropout(dropout_amt))
model.add(Dense(7))
model.add(BatchNormalization())
model.add(Activation("softmax"))

model.summary()

model.compile(
    optimizer=Adam(learning_rate=0.0001),
    loss=categorical_crossentropy,
    metrics=[metrics.categorical_accuracy],
)

model.fit(
    x_train,
    y_train,
    batch_size=64,
    epochs=50,
    verbose=1,
    validation_data=(x_test, y_test),
    shuffle=True
)
