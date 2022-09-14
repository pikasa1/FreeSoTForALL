FRotator Angle = *(FRotator*)(currentCannon + offsets.Cannon_ServerPitch);
FRotator compAngle = GetRotation((UObject*)root);
Angle += compAngle;

FVector vForward = RotationToVector(Angle);
FVector Pos = GetLocation((UObject*)root);
Pos.Z += 100;
Pos = Pos + (vForward  * 150);
