auto cannon = static_cast<ACannon*>(actor);
	if (cannon->LoadableComponent->LoadableComponentState.LoadableState != ELoadableState::ELoadableState__Loaded)
		return;

	float gravity_scale = cannon->ProjectileGravityScale;
	float gravity = 981.f * gravity_scale;
	float launch_speed = cannon->ProjectileSpeed;

	FRotator Angle = FRotator(cannon->ServerPitch, cannon->ServerYaw, 0);
	FRotator compAngle = cannon->RootComponent->K2_GetComponentRotation();
	Angle.Pitch += compAngle.Pitch;
	Angle.Yaw += compAngle.Yaw;
	Angle.Roll += compAngle.Roll;

	FVector vForward = UKismetMathLibrary::Conv_RotatorToVector(Angle);
	FVector Pos = cannon->K2_GetActorLocation();
	Pos.Z += 100;
	Pos = Pos + (vForward * 150);
	FVector velocity = vForward * launch_speed;

	if (GetLocalPlayer()->GetCurrentShip())
		velocity = velocity + GetLocalPlayer()->GetCurrentShip()->GetVelocity();
